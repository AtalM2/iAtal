// -*- c-basic-offset: 2; -*-
#include "map.h"

#include "exceptions/model/bad-parameters-exception.h"
#include <boost/algorithm/string.hpp>

using namespace iatal;

BOOST_PYTHON_MODULE(elements)
{
  boost::python::class_<Map>("Map")
    .def("getItem", &Map::getItem)
    .def("setItem", &Map::setItem)
    .def("goForward", &Map::goForward)
    .def("setDirection", &Map::setDirection)
    .def("setRobotImage", &Map::setRobotImages)
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

std::pair< unsigned int, unsigned int >
Map::getPosition()
  const
{
  return std::pair< unsigned int, unsigned int>(
    posXRobot,
    posYRobot
  );
}

void Map::setDirection(int x, int y)
{
  direction.first = x;
  direction.second = y;
}


void
Map::setRobotImages(const std::string & north,
		    const std::string & south,
		    const std::string & east,
		    const std::string & west)
{
  Glib::RefPtr< const Gdk::Pixbuf > imageN,
    imageS,
    imageE,
    imageW;
  
  try
    {
      imageN = Gdk::Pixbuf::create_from_file(north);
      imageS = Gdk::Pixbuf::create_from_file(south);
      imageE = Gdk::Pixbuf::create_from_file(east);
      imageW = Gdk::Pixbuf::create_from_file(west);
    }
  catch (const Glib::FileError & ex)
    {
      throw ex;
    }
  catch (const Gdk::PixbufError & ex)
    {
      throw ex;
    }

  robotImgs_ = {
    {"north", imageN},
    {"south", imageS},
    {"east", imageE},
    {"west", imageW}
  };
}

Glib::RefPtr< const Gdk::Pixbuf >
Map::getRobotImage()
  const
{
  Glib::RefPtr< const Gdk::Pixbuf > p;
  auto it = robotImgs_.find(getDirection());
  if (it == robotImgs_.end())
    {
      throw BadParametersException(
	"the key given to obtain the robot's image isn't a direction.");
    }
  return it->second;
}


std::string Map::getDirection()
  const
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
    return "east";
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

    //std::cout << "x:" << xTarget << ",y:" << yTarget << std::endl;
    if ( this->width > xTarget && this->height > yTarget )
    {
      std::vector< std::string > toks;
      std::string gotString =
	this->getLayer(level).getTile(xTarget, yTarget);
      boost::split(toks,gotString,boost::is_any_of(":"));
      res = toks[0];
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

