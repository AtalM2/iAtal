// -*- c-basic-offset: 2; -*-
#include "map.h"

Map::Map(unsigned int width,
         unsigned int height)
  : height(height),
    width(width),
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
