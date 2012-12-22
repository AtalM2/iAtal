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

#ifndef TMX_TILESET_H
#define	TMX_TILESET_H

#include <gtkmm/application.h>

class TmxTileset {
public:

  typedef std::map< unsigned int, Glib::ustring > map;
  
  TmxTileset();
  virtual ~TmxTileset();

  void setSpacing(unsigned int spacing);
  unsigned int getSpacing() const;

  void setTileHeight(unsigned int tileHeight);
  unsigned int getTileHeight() const;

  void setTileWidth(unsigned int tileWidth);
  unsigned int getTileWidth() const;

  void setHeight(unsigned int height);
  unsigned int getHeight() const;

  void setWidth(unsigned int width);
  unsigned int getWidth() const;

  void setName(Glib::ustring name);
  Glib::ustring getName() const;

  void setImage(Glib::ustring image);
  Glib::ustring getImage() const;

  void setFirstGid(unsigned int firstGid);
  unsigned int getFirstGid() const;

  void setProperty(unsigned int id, Glib::ustring value);
  Glib::ustring getProperty(unsigned int id) const;
  
  const map & getProperties() const;

private:
  map propertiesList_;
  unsigned int firstGid_,
    tileWidth_,
    tileHeight_,
    width_,
    height_,
    spacing_;
  Glib::ustring image_;

};

#endif	/* TMX_TILESET_H */

