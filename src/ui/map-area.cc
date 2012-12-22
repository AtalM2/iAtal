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

#include "map-area.h"

#include <exception>
#include <iostream>

#include <gdkmm/general.h> // set_source_pixbuf()
#include <gdkmm/pixbuf.h>
#include <glibmm/fileutils.h>
#include <glibmm/ustring.h>

#include "controllers/app-controller.h"
#include "controllers/map-controller.h"
#include "controllers/strategy-controller.h"

using namespace iatal;

MapArea::MapArea()
{
  set_margin_left(5);
  set_margin_right(5);
  set_margin_top(5);
  set_margin_bottom(5);
  
  set_halign(Gtk::Align::ALIGN_CENTER);
}

void
MapArea::setMap(const std::shared_ptr< Map > & map)
{
  map_ = map;
  if(map.get())
    set_size_request(map->width * map->tileWidth,
                     map->height * map->tileHeight);
}

MapArea::~MapArea()
{
}

bool
MapArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
  std::vector< Layer > layers = {
    map_->getLayer(Layer::Level::Underground),
    map_->getLayer(Layer::Level::Ground),
    map_->getLayer(Layer::Level::Object),
  };
  
  for(std::vector< Layer >::iterator it = layers.begin();
      it != layers.end();
      it++) {
    Tileset tileset = (*it).getTileset();
      
    for(unsigned int x = 0; x < map_->width; x++) {
      for(unsigned int y = 0; y < map_->height; y++) {
          
        Glib::ustring id = (*it).getTile(x, y);
	  
        if(id != "") {
          Glib::RefPtr< const Gdk::Pixbuf > image;
          try {
            image = tileset.getImage(id);
          } catch(const std::exception & e) {
	    
            std::ostringstream oss;
              
            oss << "A problem occured while "
                << "drawing the map. It seems "
                << "we're trying to draw a non "
                << "existing tile:"
                << std::endl
                << std::endl
                << e.what()
                << std::endl
                << std::endl
                << "The map has been reloaded but not "
                << "the faulty strategy.";
	    
            Glib::signal_idle().connect(
              sigc::bind(
                sigc::bind_return(
                  sigc::ptr_fun(
                    &AppController::displayWarning),
                  false),
                "Fatal error while drawing the map",
                oss.str()));

            // We have no better way (yet) to indicate the user that
            // something wrong happened.
            StrategyController::getInstance().endStrategy(true);
            MapController::getInstance().reloadMap();
            
	    
            return true;
          }
          Gdk::Cairo::set_source_pixbuf(
            cr,
            Glib::RefPtr< Gdk::Pixbuf >::cast_const(image),
            x * map_->tileWidth,
            y * map_->tileHeight);
            
          cr->paint();
        }
      }
    }
  }
  
  if(StrategyController::getInstance().shouldShowRobot())
  {
    auto p = map_->getPosition();
    Gdk::Cairo::set_source_pixbuf(
      cr,
      Glib::RefPtr< Gdk::Pixbuf >::cast_const(map_->getRobotImage()),
      p.first * map_->tileWidth +
      (map_->tileWidth - map_->getRobotImage()->get_width()) / 2,
      p.second * map_->tileHeight +
      (map_->tileHeight - map_->getRobotImage()->get_height()) / 2);
      
    cr->paint();
  }
  
  return true;
}
