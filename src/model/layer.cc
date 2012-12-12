// -*- c-basic-offset: 2; -*-
#include "layer.h"

Layer::Layer(unsigned int width,
             unsigned int height)
  : tiles_(height, std::vector< Glib::ustring >(width, "toto")),
    tileset_()
{
  
}

Layer::~Layer()
{

}

Glib::ustring
Layer::getTile(unsigned int x,
               unsigned int y)
  const
{
  return tiles_.at(x).at(y);
}

void
Layer::setTile(unsigned int x,
               unsigned int y,
               Glib::ustring tile)
{
  tiles_.at(x).at(y) = tile;
}

Tileset &
Layer::getTileset()
  const
{
  return (Tileset &) tileset_;
}
