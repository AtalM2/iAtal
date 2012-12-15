// -*- c-basic-offset: 2; -*-
#ifndef MAP_H
#define MAP_H

/*
 * Python.h must be included before any standard headers.
 * http://docs.python.org/2/c-api/intro.html#includes
 */
#include <Python.h>
#include <boost/python.hpp>

#include <vector>

#include <glibmm/ustring.h>

#include "layer.h"

/*!
  \brief A Map is made of zero or more Layer.

*/
class Map
{
  
public:
  
  /*!
    \brief Initialize an empty Map of the given size.

    \param width the width of the map.
    \param height the height of the map.
  */
  Map(unsigned int posXRobot,
      unsigned int posYRobot,
      std::pair<int,int> direction,
      unsigned int width,
      unsigned int height,
      unsigned int tileWidth,
      unsigned int tileHeight);


  /*!
    \brief Initialize an empty Map of the given size.

    \param width the width of the map.
    \param height the height of the map.
  */
  Map(unsigned int width,
      unsigned int height,
      unsigned int tileWidth,
      unsigned int tileHeight);


  const unsigned int height; //!< The height of the map in cells

  const unsigned int width; //!< The width of the map in cells

  const unsigned int tileHeight; //!< The height of the cells

  const unsigned int tileWidth; //!< The width of the cells

  /*!
    \brief Returns the Layer at the given level.

    \param layer An integer which denotes the chosen level.
    \return The selected Layer.
  */
  Layer& getLayer(Layer::Level level);  

  //tmp shit
  std::string getHello();
  
  Glib::ustring getItem(Layer::Level level, unsigned int range);
  
  Map();
  
  /*!
    \brief Default destructor.

  */
  virtual ~Map();

  /*!
    \brief Shortcuts for orientation

   */
  static const std::pair< int, int > North, //!< Facing north.
    South, //!< Facing south.
    West, //!< Facing west.
    East; //!< Facing east.

protected:
  
 private:
  unsigned int posXRobot; //!< The x postion of the robot.
  unsigned int posYRobot; //!< The y position of the robot.
  std::pair<int,int> direction; //!< The direction of the robot.
  std::vector< Layer > layers_; //!< The set of Layer
};

#endif // MAP_H
