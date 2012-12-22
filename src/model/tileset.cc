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

#include "tileset.h"

#include "exceptions/model/bad-parameters-exception.h"

using namespace iatal;

Tileset::Tileset() :
  tilesList_()
{
  
}

Tileset::~Tileset()
{
  
}

Glib::RefPtr< const Gdk::Pixbuf >
Tileset::getImage(Glib::ustring tile)
  const
{
  Glib::RefPtr< const Gdk::Pixbuf > p;
  std::map< Glib::ustring,
            Glib::RefPtr< const Gdk::Pixbuf >
            >::const_iterator it = tilesList_.find(tile);
  if (it != tilesList_.end())
  {
    p = it->second;
  }
  else
  {
    throw BadParametersException(
      "Trying to access to a non existing property in a tileset.");
  }
  return p;
}

void
Tileset::setImage(Glib::ustring tile,
                  Glib::RefPtr< const Gdk::Pixbuf > image)
{
  tilesList_[tile] = image;
}
