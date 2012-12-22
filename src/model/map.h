// -*- c-basic-offset: 2; c-indentation-style: ellemtel; -*-

//  Copyright (C) 2012

// This file is part of iAtal.

// iAtal is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// iAtal is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with iAtal.  If not, see <http://www.gnu.org/licenses/>.

#ifndef MAP_H
#define MAP_H

/*
 * Python.h must be included before any standard headers.
 * http://docs.python.org/2/c-api/intro.html#includes
 */
#include <Python.h>
#include <boost/python.hpp>

#include <vector>

#include <gdkmm/pixbuf.h>
#include <glibmm/ustring.h>
#include <glibmm/fileutils.h>

#include "layer.h"

namespace iatal
{
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


    /*!
      \brief empty constructor
    */
    Map();


    const unsigned int height; //!< The height of the map in cells

    const unsigned int width; //!< The width of the map in cells

    const unsigned int tileHeight; //!< The height of the cells

    const unsigned int tileWidth; //!< The width of the cells

    /*!
      \brief Returns the Layer at the given level.

      \param layer An integer which denotes the chosen level.
      \return The selected Layer.
    */
    iatal::Layer& getLayer(iatal::Layer::Level level);


    /*!
      \brief Gets the item on the given layer at the given range (robot dependant)

      \param level The level of the layer
      \param range The distance from the robot
    */
    std::string getItem(iatal::Layer::Level level,
                        unsigned int range);

    /*!
      \brief Sets the item on the given layer at the given range (robot dependant)

      \param level The level of the layer
      \param range The distance from the robot
      \param newTile The string defining the new tile to put.
    */
    void setItem(iatal::Layer::Level level,
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
      \brief sets the position of the robot

    */
    void setPosition(unsigned int x, unsigned y);

    /*!
      \brief gets the position of the robot

    */
    std::pair< unsigned int, unsigned int >
      getPosition() const;
  
    /*!
      \brief Sets the robot direction. Used in initialization.

    */
    void setDirection(int x, int y);

    /*!
      \brief Get the robot direction. Used as a compass.

    */
    std::string getDirection() const;

    /*!
      \brief sets the 4 sprites used to draw the robot

      \param north The sprite when the current direction is north
      \param west The sprite when the current direction is west
      \param south The sprite when the current direction is south
      \param east The sprite when the current direction is east

    */
    void setRobotImages(const std::string & north,
                        const std::string & south,
                        const std::string & east,
                        const std::string & west);

    /*!
      \brief Get the robot image depending on its direction.

    */
    Glib::RefPtr< const Gdk::Pixbuf > getRobotImage() const;

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

    std::map<
      std::string,
      Glib::RefPtr< const Gdk::Pixbuf >
      > robotImgs_;//!< The sprites used for the robot. The key is its direction.
  
    std::vector< iatal::Layer > layers_; //!< The set of Layer
  };
}

#endif // MAP_H
