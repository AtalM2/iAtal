// -*- c-basic-offset: 2; -*-
#include "layer.h"

Layer::Layer()
{

}

Layer::Layer(unsigned int width,
             unsigned int height)
  : tiles_(height),
    tileset_()
{
  std::vector< std::vector < Glib::ustring > >::iterator it =
    tiles_.begin();
  for(; it != tiles_.end(); it++)
    {
      it->resize(width);
      std::vector< Glib::ustring >::iterator it2 = it->begin();
      for(; it2 != it->end(); it2++)
	{
	  *it2 = "";
	}
    }
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
