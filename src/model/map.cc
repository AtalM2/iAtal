// -*- c-basic-offset: 2; -*-
#include "map.h"

Map::Map(unsigned int width,
         unsigned int height)
  : layers_(3)
{
  std::vector< Layer >::iterator it = layers_.begin();
  while(it != layers_.end())
  {
    Layer l(width, height);
    *it = l;
    it++;
  }
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






