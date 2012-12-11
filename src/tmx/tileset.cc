#include "tileset.h"
#include <iostream>

Tileset::Tileset() {

}

Tileset::~Tileset() {

}

void Tileset::setSpacing(unsigned int spacing) {
	this->spacing_ = spacing;
}

unsigned int Tileset::getSpacing() const {
	return spacing_;
}

void Tileset::setTileHeight(unsigned int tileHeight) {
	this->tileHeight_ = tileHeight;
}

unsigned int Tileset::getTileHeight() const {
	return tileHeight_;
}

void Tileset::setTileWidth(unsigned int tileWidth) {
	this->tileWidth_ = tileWidth;
}

unsigned int Tileset::getTileWidth() const {
	return tileWidth_;
}

void Tileset::setName(string name) {
	this->name_ = name;
}

string Tileset::getName() const {
	return name_;
}

void Tileset::setImage(string image) {
	image_ = image;
}

string Tileset::getImage() const {
	return image_;
}
