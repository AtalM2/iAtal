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

#ifndef MAP_CONTROLLER_H
#define MAP_CONTROLLER_H

#include "model/map.h"
#include <memory>
#include <string>
#include <gtkmm.h>
#include "tmx/map-loader.h"
#include "ui/map-area.h"


class MapWindow;

class MapController
{
public:
  static MapController & getInstance()
  {
    static MapController instance;
    return instance;
  }
  
  void setWindow(const std::shared_ptr< MapWindow > & window);

  void loadMap();
  void loadMapFromFile(const Glib::ustring & filename);

  void unloadMap();
  void reloadMap();

  void redraw();

  const std::shared_ptr< iatal::Map > & getMap();
  
private:
  std::shared_ptr< iatal::Map > map_;
  std::shared_ptr< MapWindow > window_;
  Glib::ustring current_;
  MapController();
  
  // Don't Implement, singleton
  MapController(const MapController &);
  
  // Don't implement, singleton
  void operator=(const MapController &);
};
#endif // MAP_CONTROLLER_H
