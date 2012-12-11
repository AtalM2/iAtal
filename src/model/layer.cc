// -*- c-basic-offset: 2; -*-
#include "layer.h"

Layer::Layer() {

}

Layer::Layer(unsigned int width,
             unsigned int height)
  : tiles_(height) {
  tileset_ = Tileset();
  std::vector< std::vector < std::string > >::iterator it =
    tiles_.begin();
  while (it != tiles_.end()) {
    it->resize(width);
    std::vector< std::string >::iterator it2 = it->begin();
    while (it2 != it->end()) {
      *it2 = std::string("");
      it2++;
    }
    it++;
  }
}

Layer::~Layer() {

}

std::string
Layer::getTile(unsigned int x,
               unsigned int y)
  const {
  return tiles_.at(x).at(y);
}

void
Layer::setTile(unsigned int x,
               unsigned int y,
               std::string tile) {
  tiles_.at(x).at(y) = tile;
}

Tileset
Layer::getTileset()
  const {
  return tileset_;
}
