//-*- c-basic-offset: 2; -*-
#ifndef MODEL_H
#define MODEL_H

#include "map.h"
#include <iostream>


/*
  \brief The Model, containing the robot, the Map and useful methods.

*/
class Model
{

public:

  /*!  
    \brief Initialize a Model with a robot on the given position and a
    Map of the given size.

    \param posXRobot The x position of the robot.
    \param posYRobot The y position of the robot.
    \param direction The direction of the robot.
    \param width The width of the Map.
    \param height The height of the map.
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

    \param level An integer wich denotes the chosen Level.
    \param range The number of tiles between the robot and the target
    tile.
  */
  Glib::ustring getItem(Layer::Level level, unsigned int range);

  /*!
    \brief Changes the direction of the robot by turning him 90° left.
  */
  void turnLeft();

  /*
    \brief The robot makes one step in its current direction.
  */
  void goOn();

  /*!
    \brief Should disappear. Just displaying some info.
  */
  void tempDisplay();

  static constexpr auto North = std::pair< int, int >(0, 1); //!< Facing north
  static constexpr auto South = std::pair< int, int >(0,-1); //!< Facing south
  static constexpr auto West = std::pair< int, int >(-1,0); //!< Facing west
  static constexpr auto East = std::pair< int, int >(1,0); //!< Facing east

  ~Model();

private:
  unsigned int posXRobot; //!< The x postion of the robot.
  unsigned int posYRobot; //!< The y position of the robot.
  std::pair<int,int> direction; //!< The direction of the robot.
  Map map; //!< The Map.

};

#endif // MODEL_H
