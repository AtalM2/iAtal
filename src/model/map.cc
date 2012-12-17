// -*- c-basic-offset: 2; -*-
#include "map.h"

BOOST_PYTHON_MODULE(elements)
{
  boost::python::class_<Map>("Map")
    .def("getItem", &Map::getItem)
    .def("setItem", &Map::setItem)
    .def("goForward", &Map::goForward)
    .def("setDirection", &Map::setDirection)
    .def("compass", &Map::getDirection)
    .def("setPosition", &Map::setPosition)
    .def("turnRight", &Map::robotTurnRight)
    .def("turnLeft", &Map::robotTurnLeft);
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
    tileWidth(10),
    layers_(Layer::Level::LastLevel + 1, Layer(width, height))
{
}


void Map::setPosition(unsigned int x, unsigned y)
{
  if (width > x && height > y)
    {
      posXRobot = x;
      posYRobot = y;
    }
}

void Map::setDirection(int x, int y)
{
  direction.first = x;
  direction.second = y;
}

std::string Map::getDirection()
{
  if (direction.first == 0 && direction.second == 1)
  {
    return "south";
  }
  if (direction.first == -1 && direction.second == 0)
  {
    return "west";
  }
  if (direction.first == 0 && direction.second == -1)
  {
    return "north";
  }
  if (direction.first == 1 && direction.second == 0)
  {
    return "south";
  }
  return "";
}

std::string Map::getItem(Layer::Level level, unsigned int range)
{
  std::string res = "nothing";
  if (static_cast<int>(posXRobot)
      + static_cast<int>(range) * direction.first >= 0
      && static_cast<int>(posYRobot)
      + static_cast<int>(range) * direction.second >= 0)
  {
    unsigned int xTarget = posXRobot + (range * direction.first);
    unsigned int yTarget = posYRobot + (range * direction.second);

    std::cout << "x:" << xTarget << ",y:" << yTarget << std::endl;
    if ( this->width > xTarget && this->height > yTarget )
    {
      res = this->getLayer(level).getTile(xTarget, yTarget);
    }
  }
  return res;

}

void Map::setItem(Layer::Level level,
		  unsigned int range,
		  std::string newTile)
{
  if (static_cast<int>(posXRobot)
      + static_cast<int>(range) * direction.first >= 0
      && static_cast<int>(posYRobot)
      + static_cast<int>(range) * direction.second >= 0)
      {
        unsigned int xTarget = posXRobot + (range * direction.first);
        unsigned int yTarget = posYRobot + (range * direction.second);

        if ( this->width > xTarget && this->height > yTarget )
        {
          this->getLayer(level).setTile(xTarget, yTarget, newTile);
        }
      }
}

void Map::robotTurnRight()
{
  if (direction.first == 0)
    {
      direction.first = -direction.second;
      direction.second = 0;
    }
  else
    {
      direction.second = direction.first;
      direction.first = 0;
    }
}

void Map::robotTurnLeft()
{
  if (direction.first == 0)
    {
      direction.first = direction.second;
      direction.second = 0;
    }
  else
    {
      direction.second = -direction.first;
      direction.first = 0;
    }
}

void Map::goForward()
{
  if (direction.first + static_cast<int>(posXRobot) >= 0
      && direction.second + static_cast<int>(posYRobot) >= 0)
  {
    unsigned int moveX = posXRobot + direction.first;
    unsigned int moveY = posYRobot + direction.second;

    if ( this->width > moveX && this->height > moveY )
    {
      posXRobot += direction.first;
      posYRobot += direction.second;
    }
  }
}


Map::~Map()
{

}

Layer&
Map::getLayer(Layer::Level level)
{
  return layers_.at(static_cast<unsigned int>(level));
}

