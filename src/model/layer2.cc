// -*- c-basic-offset: 2; -*-
#include "layer2.h"

Layer2::Level Layer2::identity_(Layer2::Level x) { return x; }

Layer2::Layer2(unsigned int width,
             unsigned int height)
  : tiles_(height, std::vector< Glib::ustring >(width, "toto")),
    tileset_()
{

}

Layer2::~Layer2()
{

}

Glib::ustring
Layer2::getTile(unsigned int x,
               unsigned int y)
  const
{
  return tiles_.at(x).at(y);
}

void
Layer2::setTile(unsigned int x,
               unsigned int y,
               Glib::ustring tile)
{
  tiles_.at(x).at(y) = tile;
}

Tileset &
Layer2::getTileset()
  const
{
  return (Tileset &) tileset_;
}
