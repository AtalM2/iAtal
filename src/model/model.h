//-*- c-basic-offset: 2; -*-
#ifndef MODEL_H
#define MODEL_H

#include "map.h"
#include <iostream>


/*
  \brief The model, containing the robot, the map and useful methods

*/
class Model
{

 public:

  /*!  
    \brief Initialize a model with a robot on the given position and a
    map of the given size.

    \param posXRobot the x position of the Robot.
    \param posYRobot the y position of the Robot.
    \param direction the direction of the Robot
    \param width the width of the map.
    \param height the height of the map.
  */
  Model(unsigned int posXRobot,
	unsigned int posYRobot,
	std::pair<int,int> direction,
	unsigned int width,
	unsigned int height,
	unsigned int tileWidth,
	unsigned int tileHeight);

  /*!
    \brief Gets a tile value.

    \param level an integer wich denotes the chosen level.
    \param range the number of tiles between the robot and the target
    tile.
  */
  Glib::ustring getItem(Layer::Level level, unsigned int range);

  void turnLeft();

  void tempDisplay();

  /*
  typedef enum
  {
    North = std::pair<int,int>(0,1), //!< Facing north
    South = std::pair<int,int>(0,-1), //!< Facing south
    West = std::pair<int,int>(-1,0), //!< Facing west
    East = std::pair<int,int>(1,0) //!< Facing east

  }Direction;
  */

  ~Model();

 private:
  unsigned int posXRobot;
  unsigned int posYRobot;
  std::pair<int,int> direction;
  Map map;



};

#endif // MODEL_H
