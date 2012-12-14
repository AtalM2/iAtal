// -*- c-basic-offset: 2; -*-

#include <map>

#include "tmx-tileset.h"
#include "exceptions/tmx/tmx-exception.h"

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

void TmxTileset::setHeight(unsigned int height) {
  this->height_ = height;
}

unsigned int TmxTileset::getHeight() const {
  return height_;
}

void TmxTileset::setWidth(unsigned int width) {
  this->width_ = width;
}

unsigned int TmxTileset::getWidth() const {
  return width_;
}

void TmxTileset::setImage(Glib::ustring image) {
  image_ = image;
}

Glib::ustring TmxTileset::getImage() const {
  return image_;
}

void TmxTileset::setFirstGid(unsigned int firstGid) {
  firstGid_ = firstGid;
}

unsigned int TmxTileset::getFirstGid() const {
  return firstGid_;
}

void TmxTileset::setProperty(unsigned int id, Glib::ustring value) {
  propertiesList_[id] = value;
}

Glib::ustring TmxTileset::getProperty(unsigned int id) const
{
  if(!id)
    return "";
  std::map<unsigned int, Glib::ustring>::const_iterator it = propertiesList_.find(id);
  if (it != propertiesList_.end()) {
    return it->second;
  } else {
    throw TmxException("prop non existing");
  }
}

const std::map< unsigned int, Glib::ustring > &
TmxTileset::getProperties()
  const
{
  return propertiesList_;
}
