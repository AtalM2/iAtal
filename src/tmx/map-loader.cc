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

using namespace tinyxml2;
using namespace std;

Map MapLoader::getMap(string tmxPath)
{
	Map map(10, 10);
	XMLDocument tmx;
	// Chargement du fichier tmx
	tmx.LoadFile(tmxPath.c_str());
	if (tmx.ErrorID() != XML_SUCCESS)
	  {
	    cout << "Impossible de charger le fichier tmx : " << (int) tmx.ErrorID() << endl;
	    return map;
	  }

	// Récupération des tilesets
	XMLElement* tilsetSurface =
	  tmx.FirstChildElement("map")->FirstChildElement("tileset");
	XMLElement* tilsetObjet = tilsetSurface->NextSiblingElement("tileset");
	XMLElement* tilsetProfond = tilsetObjet->NextSiblingElement("tileset");

	// int surfaceFirstgid = tilsetSurface->IntAttribute("firstgid");
	Tileset surface(tilsetSurface);

	// int objetFirstgid = tilsetObjet->IntAttribute("firstgid");
	Tileset objet(tilsetObjet);

	// int profondFirstgid = tilsetProfond->IntAttribute("firstgid");
	Tileset profond(tilsetProfond);

	cout << "Spacing : " << profond.GetSpacing() << endl;

	// Récupération des layers
	XMLElement* layer =
	  tmx.FirstChildElement("map")->FirstChildElement("layer");
	XMLElement* layerSurface = NULL;
	XMLElement* layerObjet = NULL;
	XMLElement* layerProfond = NULL;

	for (int i = 0; i < 3; i++) {
		string name = layer->Attribute("name");
		if (name == "Profond") {
			layerProfond = layer;
		} else if (name == "Surface") {
			layerSurface = layer;
		} else if (name == "Objet") {
			layerObjet = layer;
		} else {
			cout << "Layer incompatible détécté : " << name << endl;
		}
		layer = layer->NextSiblingElement("layer");
	}

	// Vérification de la taille des layers
	int width;
	int height;
	width = layerSurface->IntAttribute("width");
	height = layerSurface->IntAttribute("height");
	if (width != layerObjet->IntAttribute("width") ||
			height != layerObjet->IntAttribute("height") ||
			width != layerProfond->IntAttribute("width") ||
			height != layerProfond->IntAttribute("height")) {
		cout << "Les layers ne font pas la même taille" << endl;
		return map;
	}
	return map;

	//	XMLElement* titleElement = tmx.FirstChildElement("PLAY")->FirstChildElement("TITLE");
	//	const char* title = titleElement->GetText();
	//	printf("Name of play (1): %s\n", title);
	//
	//	XMLText* textNode = titleElement->FirstChild()->ToText();
	//	title = textNode->Value();
	//	printf("Name of play (2): %s\n", title);


}

