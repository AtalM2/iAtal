#include "map.h"

Map::Map(unsigned int width,
	 unsigned int height)
  : layers_(4)
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

Layer
Map::getLayer(int layer)
  const
{
  return layers_.at(layer);
}
