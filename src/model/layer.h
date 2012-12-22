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

#ifndef LAYER_H
#define LAYER_H

#include <Python.h>
#include <boost/python.hpp>

#include <algorithm>
#include <string>
#include <vector>

#include <glibmm/ustring.h>

#include "tileset.h"

namespace iatal
{
  /*!
    \brief A Layer is composed of a matrix of tiles and a Tileset.

    Each tile of the matrix is a reference to a tile in the Tileset.

    Thus, the real properties are stored in the Tileset rather than in
    the matrix itself.

    There are two reasons to do so:
    - That's how TMX stores data so it's easier to do it the same way.
    - It takes less space in memory at the cost of another indirection.
  */
  class Layer {
  public:

    /*!
      \brief Construct a Layer of the given size.

      \param width The width of the Layer.
      \param height The height of the Layer.
    */
    Layer(unsigned int width, unsigned int height);

    /*!
      \brief Default destructor.

    */
    virtual ~Layer();

    /*!
      \brief Returns a reference to the tile at the given position.

      The reference can be used to fetch the real tile in the Tileset of
      the Layer.
    
      \param x The x-coordinate or abscissa.
      \param y The y-coordinate or ordinate.
      \return The reference of the current tile.
    */
    Glib::ustring getTile(unsigned int x, unsigned int y) const;

    /*!
      \brief Change the reference of the tile at the given position.

      The reference has to be valid, that is, it must exist in the
      Tileset of the Layer.

      \param x The x-coordinate or abscissa.
      \param y The y-coordinate or ordinate.
      \param tile The new reference of the current tile.
    */
    void setTile(unsigned int x, unsigned int y, Glib::ustring tile);

    /*!
      \brief Returns the Tileset of the Layer.

      \return The Tileset of the Layer.
    */
    Tileset & getTileset();




    /*!
      \brief An an enumeration used to select a Layer in a Map.

    */
  
    /*
     * If you modify this enum by adding or removing Level, DO NOT
     * FORGET TO UPDATE LastLevel if needed.
     *
     * Moreover, the elements have to be in the ascending order withtout
     * "holes", and the first element has to be 0.
     */
    typedef enum
    {
      Underground = 0,          //!< The Underground Level
      Ground = 1,               //!< The Ground Level
      Air = 2,                  //!< The Air Level
      Object = 3,               //!< The Object Level
      LastLevel = Object        //!< Equal to the last level of the enum
    } Level;

	
    /*!
     * get from enum
     * 
     */
    Level identity_(Level x);


  private:
    std::vector< std::vector< Glib::ustring > > tiles_; //!< The matrix of tiles.
    Tileset tileset_; //!< The Tileset attached to the Layer.

  };
}

#endif // LAYER_H
