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
    map(width,height,tileWidth,tileHeight)
{
  this->direction = direction;
}


Model::~Model()
{

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

void Model::tempDisplay()
{
  std::cout << posXRobot << std::endl;
  std::cout << "dir : " << direction.first << "," << direction.second << std::endl;
}
