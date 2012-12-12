// -*- c-basic-offset: 2; -*-
#include "map.h"

Map::Map(unsigned int width,
         unsigned int height)
  : layers_(Layer::LastLevel, Layer(width, height))
{
  
}

Map::~Map()
{
  
}

Layer&
Map::getLayer(Layer::Level level)
  const
{
  return (Layer &) layers_.at(level);
}






