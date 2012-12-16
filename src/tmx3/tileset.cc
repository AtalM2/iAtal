#include "tileset.h"
#include <map>
#include <iostream>

using namespace tmx;

Tileset::Tileset() :
    tiles_() {

}

Tileset::~Tileset() {

}

void
Tileset::setImage(Glib::RefPtr< const Gdk::Pixbuf > image) {
	image_ = image;
}

Glib::RefPtr< const Gdk::Pixbuf >
Tileset::getImage() const {
	return image_;
}

void
Tileset::setSpacing(unsigned int spacing) {
	spacing_ = spacing;
}

unsigned int
Tileset::getSpacing() const {
	return spacing_;
}

void
Tileset::setTileHeight(unsigned int tileHeight) {
	tileHeight_ = tileHeight;
}

unsigned int
Tileset::getTileHeight() const {
	return tileHeight_;
}

void
Tileset::setTileWidth(unsigned int tileWidth) {
	tileWidth_ = tileWidth;
}

unsigned int
Tileset::getTileWidth() const {
	return tileWidth_;
}

void
Tileset::setName(Glib::ustring name) {
	name_ = name;
}

Glib::ustring
Tileset::getName() const {
	return name_;
}

void
Tileset::setFirstgid(unsigned int firstgid) {
	firstgid_ = firstgid;
}

unsigned int
Tileset::getFirstgid() const {
	return firstgid_;
}

void
Tileset::setTile(unsigned int id, Tile tile) {
	tiles_[id] = tile;
}

Tile
Tileset::getTile(unsigned int id) const {
	if (!id) {
		return Tile();
	}
	std::map<unsigned int, Tile>::const_iterator it = tiles_.find(id);
	if (it != tiles_.end()) {
		return it->second;
	} else {
		return Tile();
	}
}

void
Tileset::display(std::ostream & out) const {
	out << "Tileset : " << std::endl
        << "Name : " << name_
        << " - FirstGid : " << firstgid_
        << " - TileHeight : " << tileHeight_
        << " - TileWidth : " << tileWidth_
        << " - Spacing : " << spacing_ << std::endl
        << "Image : " << image_ << std::endl
        << "Tiles : " << std::endl;
	std::map<unsigned int, Tile>::const_iterator it;
	for (it = tiles_.begin(); it != tiles_.end(); ++it) {
		out << it->first << " - " << it->second << std::endl;
	}
}

std::ostream &
operator<<(std::ostream &out, const Tileset & tileset) {
	tileset.display(out);
	return out;
}
