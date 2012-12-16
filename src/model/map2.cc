// -*- c-basic-offset: 2; -*-
#include "model/map2.h"

#include "exceptions/model/bad-parameters-exception.h"

Map2::Map2(unsigned int width,
	   unsigned int height,
	   unsigned int tileWidth,
	   unsigned int tileHeight)
  : height(height),
    width(width),
    tileHeight(tileHeight),
    tileWidth(tileWidth)
{

}

Map2::Map2()
  : height(10),
    width(10),
    tileHeight(10),
    tileWidth(10)
{
}


std::string Map2::getItem(const Glib::ustring & layer, unsigned int range)
{
  std::string res = "nothing";
  if (static_cast<int>(posXRobot)
      + static_cast<int>(range) * direction.first >= 0
      && static_cast<int>(posYRobot)
      + static_cast<int>(range) * direction.second >= 0)
  {
    unsigned int xTarget = posXRobot + (range * direction.first);
    unsigned int yTarget = posYRobot + (range * direction.second);

    std::cout << xTarget << yTarget << std::endl;
    if ( this->width > xTarget && this->height > yTarget )
    {
      res = this->getLayer(layer).getTile(xTarget, yTarget);
    }
  }
  return res;

}

void Map2::setItem(const Glib::ustring & layer,
		   unsigned int range,
		   std::string newTile)
{
  int xTarget = (posXRobot + range) * direction.first;
  int yTarget = (posYRobot + range) * direction.second;
  this->getLayer(layer).setTile(xTarget, yTarget, newTile);

}


void Map2::robotTurnRight()
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

void Map2::robotTurnLeft()
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

void Map2::goForward()
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


Map2::~Map2()
{

}

Layer2 &
Map2::getLayer(const Glib::ustring & layer)
{
  auto it = layers_.find(layer);
  if (it == layers_.end())
    {
      throw BadParametersException(
	"Tried to access to a non existing layer in Map::getLayer");
    }
  return it->second;
}

