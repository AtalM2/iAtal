// -*- c-basic-offset: 2; -*-
#include <map>

#include "tileset.h"

Tileset::Tileset() :
  tilesList_() {
}

Tileset::~Tileset() {

}

string Tileset::getImage(string tile) const throw (string) {
  std::map< string, string >::const_iterator it =
    tilesList_.find(tile);
  if (it != tilesList_.end()) {
    return it->second;
  } else {
    throw string("prop non existing");
  }
}

void Tileset::setImage(string tile, string image) {
  tilesList_[tile] = image;
}
