// -*- c-basic-offset: 2; -*-
#include <algorithm>
#include <iostream>
#include <vector>

#include "model/tileset.h"

#include "tmx/map-loader.h"
#include "tmx/tmx-tileset.h"
#include "tmx/utils.h"

using namespace std;
using namespace tinyxml2;

/**
 * Permet de créer et de renvoyer une Map générée à partir d'un
 * fichier TMX
 * 
 * @param tmxPath Le chemin du fichier TMX
 * @return La Map générée
 */
Map MapLoader::loadTmx(string tmxPath) throw (string) {
  // Charger le fichier TMX	
  XMLDocument tmxDoc;
  tmxDoc.LoadFile(tmxPath.c_str());
  if (tmxDoc.ErrorID() != XML_SUCCESS)
    {
      if (tmxDoc.ErrorID() == XML_ERROR_FILE_NOT_FOUND)
	{
	  throw string("Le fichier TMX "
		       + tmxPath
		       + " est introuvable");
	}
      else
	{
	  string error = Utils::intToString(tmxDoc.ErrorID());
	  throw string("Impossible de charger le fichier TMX "
		       + tmxPath
		       + " - Erreur "
		       + error);
	}
    }

  // Récupération des informations générales
  XMLElement* tmx = tmxDoc.FirstChildElement("map");
  unsigned int height = tmx->IntAttribute("height");
  unsigned int width = tmx->IntAttribute("width");
  unsigned int tileWidth = tmx->IntAttribute("tilewidth");
  unsigned int tileHeight = tmx->IntAttribute("tileheight");
  // Vérification que tous les attributs sont présents
  if (!height || !width || !tileWidth || !tileHeight)
    {
      throw string("Un attribut est mal valorisé dans ")
	+ string("l'élément MAP du TMX");
    }
  // Vérification que la map est de type orthogonal
  if (string(tmx->Attribute("orientation")) != "orthogonal")
    {
      throw string("L'orientation du TMX doit être de ")
	+ string("style orthogonal");
    }

  // Création de l'objet Map
  Map map(width, height);
  Layer basementLayer = map.getLayer(0);
  Layer groundLayer = map.getLayer(1);
  Layer objectLayer = map.getLayer(2);
  TmxTileset basementTmxTileset;
  TmxTileset groundTmxTileset;
  TmxTileset objectTmxTileset;

  // Récupération des tilesets	
  XMLElement* xmlElement = tmx->FirstChildElement("tileset");
  while (xmlElement)
    {
      bool ok = true;
      XMLElement* xmlTilesetTmp;
      unsigned int firstGid = xmlElement->IntAttribute("firstgid");
      string source = xmlElement->Attribute("source");

      // Récupération du type de tileset (externe ou interne)
      XMLDocument tsxDoc;
      if (source == "")
	{
	  xmlTilesetTmp = xmlElement;
	}
      else
	{
	  tsxDoc.LoadFile(string("resources/"
				 + source).c_str());
	  if (tsxDoc.ErrorID() != XML_SUCCESS)
	    {
	      if (tsxDoc.ErrorID() == XML_ERROR_FILE_NOT_FOUND)
		{
		  throw string("Le fichier TSX "
			       + source
			       + " est introuvable");
		}
	      else
		{
		  string error = Utils::intToString(tsxDoc.ErrorID());
		  throw string("Impossible de charger le fichier TSX "
			       + source
			       + " - Erreur "
			       + error);
		}
	    }
	  xmlTilesetTmp = tsxDoc.FirstChildElement("tileset");
	}
      // Une fois sortie, que le tileset soit interne ou externe,
      // on manipule xmlTilesetTmp pareil

      // On vérifie le name du tileset pour savoir à quel layer
      // il correspond
      Tileset tileset;
      TmxTileset* tmxTileset;
      if (string(xmlTilesetTmp->Attribute("name")) == "basement")
	{
	  tileset = basementLayer.getTileset();
	  tmxTileset = &basementTmxTileset;
	}
      else if (string(xmlTilesetTmp->Attribute("name")) == "ground")
	{
	  tileset = groundLayer.getTileset();
	  tmxTileset = &groundTmxTileset;
	}
      else if (string(xmlTilesetTmp->Attribute("name")) == "object")
	{
	  tileset = objectLayer.getTileset();
	  tmxTileset = &objectTmxTileset;
	}
      else
	{
	  ok = false;
	}
      if (ok)
	{ // Si le tileset appartient bien à un layer
	  tmxTileset->setFirstGid(firstGid);
	  tmxTileset->setSpacing(
	    xmlTilesetTmp->IntAttribute("spacing"));
	  tmxTileset->setTileHeight(
	    xmlTilesetTmp->IntAttribute("tileheight"));
	  tmxTileset->setTileWidth(
	    xmlTilesetTmp->IntAttribute("tilewidth"));
	  XMLElement* element =
	    xmlTilesetTmp->FirstChildElement("image");
	  tmxTileset->setImage(element->Attribute("source"));
	  element = xmlTilesetTmp->FirstChildElement("tile");
	  // Parcourt de la liste des tiles définies dans le tileset
	  while (element)
	    {
	      string id = element->Attribute("id");
	      unsigned int idInt =
		(unsigned int) Utils::stringToInt(id);
	      XMLElement* xmlTile =
		element
		->FirstChildElement("properties")
		->FirstChildElement("property");
	      tmxTileset
		->setProperty(idInt,
			      string(xmlTile->Attribute("name"))
			      + ":"
			      + string(
				xmlTile->Attribute("value")));
	      element =
		element->NextSiblingElement("tile");
	    }
	}
      xmlElement = xmlElement->NextSiblingElement("tileset");
    }
  
  // Récupération des layers
  xmlElement = tmx->FirstChildElement("layer");
  while (xmlElement)
    {
      TmxTileset* tmxTileset;
      Layer layer;
      bool ok = true;
      // unsigned int firstgid = 0;
      // On vérifie le name du layer
      if (string(xmlElement->Attribute("name")) == "basement")
	{
	  layer = basementLayer;
	  tmxTileset = &basementTmxTileset;
	}
      else if (string(xmlElement->Attribute("name")) == "ground")
	{
	  layer = groundLayer;
	  tmxTileset = &groundTmxTileset;
	}
      else if (string(xmlElement->Attribute("name")) == "object")
	{
	  layer = objectLayer;
	  tmxTileset = &objectTmxTileset;
	}
      else
	{
	  ok = false;
	}
      if (ok)
	{ // Si le name correspond
	  // On vérifie que la taille est cohérente
	  if ((unsigned int) xmlElement->IntAttribute("height")
	      != height
	      || (unsigned int) xmlElement->IntAttribute("width")
	      != width)
	    {
	      throw string("Il y a une incohérence entre la taille ")
		+ string("d'un layer et la taille de la map");
	    }
	  XMLElement* xmlData = xmlElement->FirstChildElement("data");
	  // On vérifie que l'encodage est supporté
	  if (string(xmlData->Attribute("encoding")) != "csv")
	    {
	      throw string("L'encodage "
			   + string(xmlData->Attribute("encoding"))
			   + " d'un layer n'est pas supporté");
	    }
	  string data = xmlData->GetText();
	
	  // Suppression des \n et des espaces
	  string tmp;
	  tmp.resize(data.size());
	  std::remove_copy(data.begin(),
			   data.end(),
			   tmp.begin(),
			   '\n');
	  std::remove_copy(tmp.begin(),
			   tmp.end(),
			   data.begin(),
			   ' ');
	
	  vector<string> dataVector = Utils::stringExplode(data,
							   ",");
	  size_t size = dataVector.size();
	  for (size_t i = 0; i < size; i++)
	    {
	      unsigned int y = i / width;
	      unsigned int x = i % width;
	      string id = dataVector.at(i);
	      unsigned int idInt =
		(unsigned int) Utils::stringToInt(id);
	      idInt = idInt - tmxTileset->getFirstGid();
	      string property = tmxTileset->getProperty(idInt);
	      cout << i
		   << " -> x:" << x
		   << " y:" << y
		   << " property:" << property
		   << endl;
	      layer.setTile(x, y, property);
	    }
	}
      xmlElement = xmlElement->NextSiblingElement("layer");
    }
  
  return map;
}

