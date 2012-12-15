// -*- c-basic-offset: 2; -*-
#include "map.h"

BOOST_PYTHON_MODULE(elements)
{
  boost::python::class_<Map>("Map")
  .def("hello", &Map::getItem)
  .def("hello", &Map::getHello);
}

Map::Map(unsigned int posXRobot,
	 unsigned int posYRobot,
	 std::pair<int,int> direction,
	 unsigned int width,
         unsigned int height,
	 unsigned int tileWidth,
         unsigned int tileHeight)
  : height(height),
    width(width),
    tileHeight(tileHeight),
    tileWidth(tileWidth),
    posXRobot(posXRobot),
    posYRobot(posYRobot),
    direction(direction),
    layers_(Layer::Level::LastLevel + 1, Layer(width, height))
{
  
}

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
Map::Map()
  : height(10),
    width(10),
    tileHeight(10),
    tileWidth(10)
{
}

std::string Map::getHello()
{
  return "Hello";
}

Glib::ustring Map::getItem(Layer::Level level, unsigned int range)
{
  int xTarget = (posXRobot + range) * direction.first;
  int yTarget = (posYRobot + range) * direction.second;

  return map.getLayer(level).getTile(xTarget, yTarget);

}

Map::~Map()
{
  
}

Layer&
Map::getLayer(Layer::Level level)
{
  return layers_.at(static_cast<unsigned int>(level));
}

