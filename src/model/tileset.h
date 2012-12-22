// -*- c-basic-offset: 2; -*-

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

#ifndef TILESET_H
#define	TILESET_H

#include <map>

#include <gdkmm/pixbuf.h>
#include <glibmm/ustring.h>

namespace iatal
{
  /*!
    \brief A Tileset stores the properties of each tiles in a dedicated
    Layer.

    Currently, the only property owned by a tile is its image.

  */
  class Tileset {
  public:

    /*!
      \brief Create an empty Tileset.

    */
    Tileset();
  
    /*!
      \brief Default destructor.

    */
    virtual ~Tileset();
  
    /*!
      \brief Returns the image of the given tile.

      \param tile The reference of a tile in the Tileset.
      \return The image of the tile referenced.
    */
    Glib::RefPtr< const Gdk::Pixbuf >
      getImage(Glib::ustring tile) const;

  
    /*!
      \brief Set the image of the given tile.

      \param tile The reference of a tile in the Tileset.
      \param image The new image of the selected tile.
    */
    void setImage(Glib::ustring tile,
		  Glib::RefPtr< const Gdk::Pixbuf > image);
  
  private:

    std::map< Glib::ustring, Glib::RefPtr< const Gdk::Pixbuf > >
      tilesList_; //!< map<reference, image>
  };
}

#endif	/* TILESET_H */
