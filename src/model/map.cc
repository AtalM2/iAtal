// -*- c-basic-offset: 2; -*-
#include "map.h"

Map::Map(unsigned int width,
         unsigned int height)
  : layers_(3, Layer(width, height))
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






