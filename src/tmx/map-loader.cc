/* 
 * File:   MapLoader.cpp
 * Author: Noemi
 * 
 * Created on 9 décembre 2012, 23:07
 */

#include "map-loader.h"
#include <iostream>
#include "tinyxml2.h"
#include "tileset.h"
#include <vector>
#include "utils.h"

using namespace tinyxml2;
using namespace std;

/**
 * Permet de créer et de renvoyer une Map générée à partir d'un fichier TMX
 * 
 * @param tmxPath Le chemin du fichier TMX
 * @return La Map générée
 */
Map MapLoader::loadTmx(string tmxPath) throw (string) {
	// Charger le fichier TMX	
	XMLDocument tmxDoc;
	tmxDoc.LoadFile(tmxPath.c_str());
	if (tmxDoc.ErrorID() != XML_SUCCESS) {
		if (tmxDoc.ErrorID() == XML_ERROR_FILE_NOT_FOUND) {
			throw string("Le fichier TMX " + tmxPath + " est introuvable");
		} else {
			string error = Utils::intToString(tmxDoc.ErrorID());
			throw string("Impossible de charger le fichier TMX " + tmxPath + " - Erreur " + error);
		}
	}

	// Récupération des informations générales
	XMLElement* tmx = tmxDoc.FirstChildElement("map");
	unsigned int height = tmx->IntAttribute("height");
	unsigned int width = tmx->IntAttribute("width");
	unsigned int tileWidth = tmx->IntAttribute("tilewidth");
	unsigned int tileHeight = tmx->IntAttribute("tileheight");
	if (!height || !width || !tileWidth || !tileHeight) { // Vérification que tous les attributs sont présents
		throw string("Un attribut est mal valorisé dans l'élément MAP du TMX");
	}
	if (string(tmx->Attribute("orientation")) != "orthogonal") { // Vérification que la map est de type orthogonal
		throw string("L'orientation du TMX doit être de style orthogonal");
	}

	// Création de l'objet Map
	Map map(width, height);
	Layer basementLayer = map.getLayer(0);
	Layer groundLayer = map.getLayer(1);
	Layer objectLayer = map.getLayer(2);

	// Récupération des tilesets	
	// TODO: utiliser les variables qui suivent :D
	// unsigned int basementFirstgid = 0;
	// unsigned int groundFirstgid = 0;
	// unsigned int objectFirstgid = 0;
	XMLElement* xmlElement = tmx->FirstChildElement("tileset");
	while (xmlElement) {
		bool ok = true;
		XMLElement* xmlTilesetTmp;
		// unsigned int firstgid = xmlElement->IntAttribute("firstgid");
		string source = xmlElement->Attribute("source");

		// Récupération du type de tileset (externe ou interne)
		XMLDocument tsxDoc;
		if (source == "") {
			xmlTilesetTmp = xmlElement;
		} else {
			tsxDoc.LoadFile(string("src/tmx/resources/" + source).c_str());
			if (tsxDoc.ErrorID() != XML_SUCCESS) {
				if (tsxDoc.ErrorID() == XML_ERROR_FILE_NOT_FOUND) {
					throw string("Le fichier TSX " + source + " est introuvable");
				} else {
					string error = Utils::intToString(tsxDoc.ErrorID());
					throw string("Impossible de charger le fichier TSX " + source + " - Erreur " + error);
				}
			}
			xmlTilesetTmp = tsxDoc.FirstChildElement("tileset");
		}
		// Une fois sortie, que le tileset soit interne ou externe, on manipule xmlTilesetTmp pareil

		// On vérifie le name du tileset pour savoir à quel layer il correspond
		Tileset tileset;
		if (string(xmlTilesetTmp->Attribute("name")) == "basement") {
			tileset = basementLayer.getTileset();
			// basementFirstgid = firstgid;
		} else if (string(xmlTilesetTmp->Attribute("name")) == "ground") {
			tileset = groundLayer.getTileset();
			// groundFirstgid = firstgid;
		} else if (string(xmlTilesetTmp->Attribute("name")) == "object") {
			tileset = objectLayer.getTileset();
			// objectFirstgid = firstgid;
		} else {
			ok = false;
		}
		if (ok) { // Si le tileset appartient bien à un layer
			tileset.setName(xmlTilesetTmp->Attribute("name"));
			tileset.setSpacing(xmlTilesetTmp->IntAttribute("spacing"));
			tileset.setTileHeight(xmlTilesetTmp->IntAttribute("tileheight"));
			tileset.setTileWidth(xmlTilesetTmp->IntAttribute("tilewidth"));
			XMLElement* element = xmlTilesetTmp->FirstChildElement("image");
			tileset.setImage(element->Attribute("source"));
			element = xmlTilesetTmp->FirstChildElement("tile");
			while (element) { // Parcourt de la liste des tiles définies dans le tileset
				Tile tile;
				tile = Tile();
				tile.setType(element->Attribute("id"));
				XMLElement* xmlTile = element->FirstChildElement("properties")->FirstChildElement("property");
				while (xmlTile) { // Parcourt de la liste des properties de la tile
					tile.setProp(xmlTile->Attribute("name"), xmlTile->Attribute("value"));
					xmlTile = xmlTile->NextSiblingElement("property");
				}
				element = element->NextSiblingElement("tile");
			}
		}
		xmlElement = xmlElement->NextSiblingElement("tileset");
	}

	// Récupération des layers
	xmlElement = tmx->FirstChildElement("layer");
	while (xmlElement) {
		Layer layer;
		bool ok = true;
		// unsigned int firstgid = 0;
		// On vérifie le name du layer
		if (string(xmlElement->Attribute("name")) == "basement") {
			layer = basementLayer;
			// firstgid = basementFirstgid;
		} else if (string(xmlElement->Attribute("name")) == "ground") {
			layer = groundLayer;
			// firstgid = groundFirstgid;
		} else if (string(xmlElement->Attribute("name")) == "object") {
			layer = objectLayer;
			// firstgid = objectFirstgid;
		} else {
			ok = false;
		}
		if (ok) { // Si le name correspond
			// On vérifie que la taille est cohérente
		  if ((unsigned int) xmlElement->IntAttribute("height") != height
		      || (unsigned int) xmlElement->IntAttribute("width") != width) {
				throw string("Il y a une incohérence entre la taille d'un layer et la taille de la map");
			}
			XMLElement* xmlData = xmlElement->FirstChildElement("data");
			// On vérifie que l'encodage est supporté
			if (string(xmlData->Attribute("encoding")) != "csv") {
				throw string("L'encodage " + string(xmlData->Attribute("encoding")) + " d'un layer n'est pas supporté");
			}
			string data = xmlData->GetText();
			data = Utils::stringReplace(data,"\n ", '\0');
			vector<string> dataVector = Utils::stringExplode(data,",");
			size_t size = dataVector.size();
			for (size_t i = 0; i<size ;i++) {
				cout << dataVector.at(i) << endl;
			}			
		}
		xmlElement = xmlElement->NextSiblingElement("layer");
	}


	return map;
}

