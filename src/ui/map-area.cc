// -*- c-basic-offset: 2; -*-
#include "map-area.h"

#include <iostream>

#include <cairomm/context.h>
#include <gdkmm/general.h> // set_source_pixbuf()
#include <gdkmm/pixbufanimation.h>
#include <glibmm/fileutils.h>

MapArea::MapArea(const std::shared_ptr< Map > & map)
  : map_(map)
{
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
    [this, & cr] (const Layer & layer)
    {
      Tileset tileset = layer.getTileset();
      for(unsigned int x = 0; x < map_->width; x++)
	{
	  for(unsigned int y = 0; y < map_->height; y++)
	    {
	      Glib::ustring id = layer.getTile(x, y);
	      if(id != "")
		{
		  Glib::RefPtr< const Gdk::Pixbuf > image =
		    tileset.getImage(id);
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
  std::cout << "<redraw/>" << std::endl;
  return true;
}

// void
// MapArea::move(int dx, int dy)
// {
//   const Cairo::RectangleInt rect_start = {x, y, 10, 10};
//   x += dx;
//   y += dy;
//   const Cairo::RectangleInt  rect_end = {x, y, 10, 10};
//   const std::vector< Cairo::RectangleInt > rect_vector {rect_start, rect_end};
//   Cairo::RefPtr< Cairo::Region > region = Cairo::Region::create(rect_vector);
//   queue_draw_region(region);
// }