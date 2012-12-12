// -*- c-basic-offset: 2; -*-
#include "model.h"

Model::Model(unsigned int posXRobot,
             unsigned int posYRobot,
             std::pair<int,int> direction,
             unsigned int width,
             unsigned int height,
             unsigned int tileWidth,
             unsigned int tileHeight)
  : posXRobot(posXRobot),
    posYRobot(posYRobot),
    map(width, height, tileWidth, tileHeight)
{
  this->direction = direction;
}

Model::~Model()
{

}

Glib::ustring Model::getItem(Layer::Level level, unsigned int range)
{
  int xTarget = (posXRobot + range) * direction.first;
  int yTarget = (posYRobot + range) * direction.second;

  return map.getLayer(level).getTile(xTarget, yTarget);

}

void Model::turnLeft()
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

void Model::goOn()
{
  posXRobot += direction.first;
  posYRobot += direction.second;
}

void Model::tempDisplay()
{
  std::cout << "pos : " << posXRobot << ", " << posYRobot << std::endl;
  std::cout << "dir : " << direction.first << ", " << direction.second << std::endl;
}

// http://stackoverflow.com/a/272965/1069569
// Static fields has to be allocated.
constexpr std::pair< int, int > Model::North;
constexpr std::pair< int, int > Model::South;
constexpr std::pair< int, int > Model::West;
constexpr std::pair< int, int > Model::East;