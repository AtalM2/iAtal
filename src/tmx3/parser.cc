#include <sstream>
#include <iostream>
#include <algorithm>
#include "parser.h"
#include "tileset.h"
#include "layer.h"

#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>

using namespace tinyxml2;

Map
Parser::parseFile(std::string filePath) {
  Map map;

  // Charger le fichier TMX
  XMLDocument tmxDoc;
  try {
    loadFile(tmxDoc, filePath);
  } catch (Exception e) {
    throw e;
  }

  // Récupération du répertoire courant
  std::string tmxFileDirectory = getFileDirectory(filePath);

  // Récupération des informations générales
  XMLElement* tmx = tmxDoc.FirstChildElement("map");
  std::string orientation = tmx->Attribute("orientation");
  unsigned int width = tmx->IntAttribute("width"),
    height = tmx->IntAttribute("height"),
    tileWidth = tmx->IntAttribute("tilewidth"),
    tileHeight = tmx->IntAttribute("tileheight");

  if (!width || !height || !tileWidth || !tileHeight) {
    std::ostringstream oss;
    oss << "L'un des attributs (height, width, tileheight, tilewidth) est égal à 0. "
	<< "La map ne peut pas être créée dans ces conditions";
    throw BadParametersException(oss.str());
  }

  map.setOrientation(orientation);
  map.setHeight(height);
  map.setWidth(width);
  map.setTileHeight(tileHeight);
  map.setTileWidth(tileWidth);


  // Récupération des tilesets
  XMLElement* xmlElement = tmx->FirstChildElement("tileset");
  while (xmlElement) {
    Tileset tileset;

    XMLElement* xmlTilesetTmp;
    std::string tsxFileDirectory;
    tileset.setFirstgid((unsigned int) xmlElement->IntAttribute("firstgid"));
    const char * sourceC = xmlElement->Attribute("source");
    std::string source;
    // Récupération du type de tileset (externe ou interne)
    XMLDocument tsxDoc;
    if (!sourceC) {
      xmlTilesetTmp = xmlElement;
      tsxFileDirectory = tmxFileDirectory;
    } else {
      source = sourceC;
      try {
	loadFile(tsxDoc, tmxFileDirectory + "/" + source);
	tsxFileDirectory = getFileDirectory(tmxFileDirectory + "/" + source);
      } catch (Exception e) {
	throw e;
      }
      xmlTilesetTmp = tsxDoc.FirstChildElement("tileset");
    }
    // Une fois sortie, quelques soit le type du tileset (interne ou externe)
    // on le manipule à travers la variable xmlTilesetTmp


    tileset.setName(std::string(xmlTilesetTmp->Attribute("name")));
    tileset.setSpacing(xmlTilesetTmp->IntAttribute("spacing"));
    tileset.setTileHeight(xmlTilesetTmp->IntAttribute("tileheight"));
    tileset.setTileWidth(xmlTilesetTmp->IntAttribute("tilewidth"));

    XMLElement* element = xmlTilesetTmp->FirstChildElement("image");
    
    source = element->Attribute("source");

    Glib::RefPtr< const Gdk::Pixbuf > image =
      Gdk::Pixbuf::create_from_file(
	tsxFileDirectory + "/" + source,
	element->IntAttribute("width"),
	element->IntAttribute("height"));

    // const char* attributeTmp = element->Attribute("trans");
    // image.setTransparency(attributeTmp ? std::string(attributeTmp) : "");

    tileset.setImage(image);

    // Parcourt de la liste des tiles définies dans le tileset
    element = xmlTilesetTmp->FirstChildElement("tile");
    while (element) {
      Tile tile;
      unsigned int id = (unsigned int) element->IntAttribute("id");
      XMLElement* xmlTile = element->FirstChildElement("properties")->FirstChildElement("property");
      while (xmlTile) {
	tile.setProperty(std::string(xmlTile->Attribute("name")), std::string(xmlTile->Attribute("value")));
	xmlTile = xmlTile->NextSiblingElement("property");
      }
      tileset.setTile(id, tile);
      element = element->NextSiblingElement("tile");
    }

    map.getTilesets().push_back(tileset);
    xmlElement = xmlElement->NextSiblingElement("tileset");
  }

  // Récupération des layers
  xmlElement = tmx->FirstChildElement("layer");
  while (xmlElement) {

    Layer layer((unsigned int) xmlElement->IntAttribute("width"), (unsigned int) xmlElement->IntAttribute("height"));
    layer.setName(std::string(xmlElement->Attribute("name")));

    XMLElement* xmlData = xmlElement->FirstChildElement("data");
    std::vector<unsigned int> data;
    // On vérifie que l'encodage est supporté
    if (std::string(xmlData->Attribute("encoding")) == "csv") {
      data = parseCsv(std::string(xmlData->GetText()));
    } else {
      std::ostringstream oss;
      oss << "L'encodage "
	  << xmlData->Attribute("encoding")
	  << " d'un layer n'est pas supporté";
      throw BadParametersException(oss.str());
    }

    for (size_t i = 0; i < data.size(); i++) {
      unsigned int y = i / layer.getWidth();
      unsigned int x = i % layer.getWidth();
      unsigned int id = data.at(i);
      layer.setTile(x, y, id);
    }
    map.getLayers().push_back(layer);
    xmlElement = xmlElement->NextSiblingElement("layer");
  }
  return map;
}

void
Parser::loadFile(tinyxml2::XMLDocument& tmxDoc, std::string filePath) {
  tmxDoc.LoadFile(filePath.c_str());
  if (tmxDoc.ErrorID() != XML_SUCCESS) {
    if (tmxDoc.ErrorID() == XML_ERROR_FILE_NOT_FOUND) {
      throw FileNotFoundException("Le fichier TMX "
				  + filePath
				  + " n'a pas été trouvé.");
    } else {
      std::ostringstream error;
      error << "Impossible de charger le fichier TMX. "
	    << "Erreur numéro : "
	    << (int) tmxDoc.ErrorID()
	    << ".";
      throw XmlException(error.str());
    }
  }
}

std::string
Parser::getFileDirectory(std::string filePath) {
  size_t pos = filePath.find_last_of("\\/");
  if (std::string::npos == pos) {
    return "";
  } else {
    return filePath.substr(0, pos);
  }
}

std::vector<unsigned int>
Parser::parseCsv(std::string data) {

  std::vector<unsigned int> intVector;
  int acc = 0;
  for(std::string::iterator it = data.begin();
      it != data.end();
      it++) {
    try {
      // Converts the current char to an integer.
      acc = (acc * 10) + boost::lexical_cast<int>(*it);
    } catch(boost::bad_lexical_cast e) { // oops it wasn't a
      // number after all.
      // Maybe it was a comma, used to separate fields.
      if (*it == ',') {
	// yay, push the accumulated value.
	intVector.push_back(acc);
      }
      // Reset the accumulator whether it was a comma or junk.
      acc = 0;
    }
  }

  return intVector;
}
