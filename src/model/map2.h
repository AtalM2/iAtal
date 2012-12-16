// -*- c-basic-offset: 2; -*-
#ifndef MAP2_H
#define MAP2_H

/*
 * Python.h must be included before any standard headers.
 * http://docs.python.org/2/c-api/intro.html#includes
 */
#include <Python.h>
#include <boost/python.hpp>

#include <vector>

#include <glibmm/ustring.h>

#include "layer2.h"

/*!
  \brief A Map is made of zero or more Layer.

*/
class Map2
{

public:

  /*!
    \brief Initialize an empty Map of the given size.

    \param width the width of the map.
    \param height the height of the map.
  */
  Map2(unsigned int posXRobot,
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
  Map2(unsigned int width,
       unsigned int height,
       unsigned int tileWidth,
       unsigned int tileHeight);


  /*!
    \brief empty constructor
   */
  Map2();


  const unsigned int height; //!< The height of the map in cells

  const unsigned int width; //!< The width of the map in cells

  const unsigned int tileHeight; //!< The height of the cells

  const unsigned int tileWidth; //!< The width of the cells

  /*!
    \brief Returns the Layer at the given level.

    \param layer An integer which denotes the chosen level.
    \return The selected Layer.
  */
  Layer2 & getLayer(const Glib::ustring & layer);

  const Tileset & getTileset() const;

  /*!
    \brief Gets the item on the given layer at the given range (robot dependant)

    \param level The level of the layer
    \param range The distance from the robot
  */
  std::string getItem(const Glib::ustring & layer,
		      unsigned int range);

  /*!
    \brief Sets the item on the given layer at the given range (robot dependant)

    \param level The level of the layer
    \param range The distance from the robot
    \param newTile The string defining the new tile to put.
   */
  void setItem(const Glib::ustring & layer,
	       unsigned int range,
	       std::string newTile);


  /*!
    \brief The robot makes one step in front of himself

  */
  void goForward();

  /*!
    \brief The robot turns on its left
  */
  void robotTurnLeft();

  /*!
    \brief The robot turns on its right.
  */
  void robotTurnRight();



  /*!
    \brief Default destructor.

  */
  virtual ~Map2();

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
  std::map< Glib::ustring, Layer2 > layers_; //!< The set of Layer
  Tileset tileset_;
};

#endif // MAP2_H
