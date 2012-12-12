// -*- c-basic-offset: 2; -*-
#include "map.h"

Map::Map(unsigned int width,
         unsigned int height,
	 unsigned int tileWidth,
         unsigned int tileHeight)
  : height(height),
    width(width),
    tileHeight(tileHeight),
    tileWidth(tileWidth),
    layers_(Layer::Level::LastLevel + 1, Layer(width, height))
{
  
}

Map::~Map()
{
  
}

Layer&
Map::getLayer(Layer::Level level)
{
  return layers_.at(static_cast<unsigned int>(level));
}
