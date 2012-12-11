#include <map>

#include "tmx-tileset.h"

TmxTileset::TmxTileset() :
propertiesList_() {

}

TmxTileset::~TmxTileset() {

}

void TmxTileset::setSpacing(unsigned int spacing) {
	this->spacing_ = spacing;
}

unsigned int TmxTileset::getSpacing() const {
	return spacing_;
}

void TmxTileset::setTileHeight(unsigned int tileHeight) {
	this->tileHeight_ = tileHeight;
}

unsigned int TmxTileset::getTileHeight() const {
	return tileHeight_;
}

void TmxTileset::setTileWidth(unsigned int tileWidth) {
	this->tileWidth_ = tileWidth;
}

unsigned int TmxTileset::getTileWidth() const {
	return tileWidth_;
}

void TmxTileset::setImage(string image) {
	image_ = image;
}

string TmxTileset::getImage() const {
	return image_;
}

void TmxTileset::setFirstGid(unsigned int firstGid) {
	firstGid_ = firstGid;
}

unsigned int TmxTileset::getFirstGid() const {
	return firstGid_;
}

void TmxTileset::setProperty(unsigned int id, string value) {
	propertiesList_[id] = value;
}

string TmxTileset::getProperty(unsigned int id) const throw (string) {
	std::map<unsigned int, string>::const_iterator it = propertiesList_.find(id);
	if (it != propertiesList_.end()) {
		return it->second;
	} else {
		throw string("prop non existing");
	}
}
