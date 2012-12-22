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

#ifndef MAP_AREA_H
#define MAP_AREA_H

#include "model/map.h"

#include <memory>

#include <cairomm/context.h>
#include <gtkmm/drawingarea.h>

/**
 * Widget used to display the map.
 */
class MapArea : public Gtk::DrawingArea
{

 public:
  /**
   * Constructor, sets the proper spacing and align properties.
   */
  MapArea();
  
  /**
   * Swaps the underlying map.
   * 
   * \param map The new map to use.
   */
  void setMap(const std::shared_ptr< iatal::Map > & map);

  /**
   * Destructor.
   */
  virtual ~MapArea();

 protected:
  /**
   * Redefinition of the on_draw method. Goes through the model and
   * updates the drawing area accordingly.
   */
  virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);
  
 private:
  /**
   * Pointer to the map displayed.
   */
  std::shared_ptr< iatal::Map > map_;
};

#endif // MAP_AREA_H
