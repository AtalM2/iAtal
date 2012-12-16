// -*- c-basic-offset: 2; -*-
#include "map-area.h"

#include <exception>
#include <iostream>

#include <gdkmm/general.h> // set_source_pixbuf()
#include <gdkmm/pixbuf.h>
#include <glibmm/fileutils.h>
#include <glibmm/ustring.h>

#include "controllers/app-controller.h"

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

bool MapArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
  std::vector< Layer > layers = {
    map_->getLayer(Layer::Level::Underground),
    map_->getLayer(Layer::Level::Ground),
    map_->getLayer(Layer::Level::Object),
  };
  
  std::for_each(
    layers.begin(),
    layers.end(),
    [this, & cr] (const Layer & layer) {
      Tileset tileset = layer.getTileset();
      
      for(unsigned int x = 0; x < map_->width; x++) {
        for(unsigned int y = 0; y < map_->height; y++) {
          
          Glib::ustring id = layer.getTile(x, y);
	  
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
                  << e.what()
                  << std::endl;
              
              AppController::displayWarning(
                "Fatal Error while drawing map",
                oss.str());
              
              exit(1);
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
    );
  return true;
}
