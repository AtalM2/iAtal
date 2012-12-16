#include "map.h"

using namespace tmx;

Map::Map() :
    properties_(),
    tilesets_(),
    layers_() {
}

Map::~Map() {
}

std::vector<Layer> &
Map::getLayers() {
	return layers_;
}

std::vector<Tileset> &
Map::getTilesets() {
	return tilesets_;
}

std::map<std::string, std::string>
Map::getProperties() const {
	return properties_;
}

std::string
Map::getProperty(const std::string & key) const {
	if (key == "") {
		return "";
	}
	std::map<std::string, std::string>::const_iterator it = properties_.find(key);
	if (it != properties_.end()) {
		return it->second;
	} else {
		return "";
	}
}

void
Map::setProperty(const std::string & key,
		 const std::string & value) {
	properties_[key] = value;
}

void
Map::setTileHeight(unsigned int tileHeight) {
	tileHeight_ = tileHeight;
}

unsigned int
Map::getTileHeight() const {
	return tileHeight_;
}

void
Map::setTileWidth(unsigned int tileWidth) {
	tileWidth_ = tileWidth;
}

unsigned int
Map::getTileWidth() const {
	return tileWidth_;
}

void
Map::setHeight(unsigned int height) {
	height_ = height;
}

unsigned int
Map::getHeight() const {
	return height_;
}

void
Map::setWidth(unsigned int width) {
	width_ = width;
}

unsigned int
Map::getWidth() const {
	return width_;
}

void
Map::setOrientation(const std::string & orientation) {
	orientation_ = orientation;
}

std::string
Map::getOrientation() const {
	return orientation_;
}

void
Map::display(std::ostream & out) const {
	out << "Map : " << std::endl
        << "Orientation : " << orientation_
        << " - Height : " << height_
        << " - Width : " << width_
        << " - TileHeight : " << tileHeight_
        << " - TileWidth : " << tileWidth_ << std::endl
        << "Properties : " << std::endl;
	std::map<std::string, std::string>::const_iterator it;
	for (it = properties_.begin(); it != properties_.end(); ++it) {
		out << it->first << " - " << it->second << std::endl;
	}
	out << "Tilesets : " << std::endl;
	for (size_t i = 0; i < tilesets_.size(); i++) {
		out << tilesets_.at(i) << std::endl;
	}
	out << "Layers : " << std::endl;
	for (size_t i = 0; i < layers_.size(); i++) {
		out << layers_.at(i) << std::endl;
	}
}

std::ostream &
operator<<(std::ostream & out, const Map & map) {
	map.display(out);
	return out;
}
