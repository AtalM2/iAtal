/* 
 * File:   tileset.cpp
 * Author: Noemi
 * 
 * Created on 10 décembre 2012, 00:35
 */

#include "tileset.h"
#include <iostream>

Tileset::Tileset(XMLElement* xml) {
	int success = 1;
	string source = xml->Attribute("source");
	XMLElement* tileset;
	XMLDocument tsx;
	if (source == "") {
		tileset = xml;
	} else {
		tsx.LoadFile(string("resources/" + source).c_str());
		if (tsx.ErrorID() != XML_SUCCESS) {
			cout << "Impossible de charger le fichier tsx : " << tsx.ErrorID() << endl;
			success = 0;
		}
		if (success == 1) {
			tileset = tsx.FirstChildElement("tileset");
		}
	}
	if (success == 1) {
		name_ = tileset->Attribute("name");
		tileHeight_ = tileset->IntAttribute("tileheight");
		tileWidth_ = tileset->IntAttribute("tilewidth");
		spacing_ = tileset->IntAttribute("spacing");
	}
}

Tileset::~Tileset() {

}

void Tileset::SetSpacing(unsigned int spacing) {
	spacing_ = spacing;
}

unsigned int Tileset::GetSpacing() const {
	return spacing_;
}

void Tileset::SetTileHeight(unsigned int tileHeight) {
	this->tileHeight_ = tileHeight;
}

unsigned int Tileset::GetTileHeight() const {
	return tileHeight_;
}

void Tileset::SetTileWidth(unsigned int tileWidth) {
	this->tileWidth_ = tileWidth;
}

unsigned int Tileset::GetTileWidth() const {
	return tileWidth_;
}

void Tileset::SetName(string name) {
	this->name_ = name;
}

string Tileset::GetName() const {
	return name_;
}