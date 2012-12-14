// -*- c-basic-offset: 2; -*-
#include "maparea.h"

#include <iostream>

#include <cairomm/context.h>
#include <gdkmm/general.h> // set_source_pixbuf()
#include <gdkmm/pixbufanimation.h>
#include <glibmm/fileutils.h>

MapArea::MapArea(const std::shared_ptr< Map > & map)
  : map_(map)
{
  set_size_request(500, 500);
}

MapArea::~MapArea()
{
}

bool MapArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
  Layer layer = map_->getLayer(Layer::Level::Underground);
  Tileset tileset = layer.getTileset();
  for(unsigned int x = 0; x < map_->width; x++)
    {
      for(unsigned int y = 0; y < map_->height; y++)
	{
	  Glib::ustring id = layer.getTile(x, y);
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
  // if (!m_image1)
  //   return false;
  // bool even = true;
  // for (int i = 0; i < 500; i += 20) {
  //   for (int j = 0; j < 500; j += 10) {
  // 	  Gdk::Cairo::set_source_pixbuf(cr,
  //                                   even ? m_image1 : m_image2,
  //                                   i,
  //                                   j);
  // 	  cr->paint();
	  
  // 	  Gdk::Cairo::set_source_pixbuf(cr,
  //                                   even ? m_image2 : m_image1,
  //                                   i + 10,
  //                                   j);
  // 	  cr->paint(); 
  // 	  even = !even;
  // 	}
  //   Gdk::Cairo::set_source_pixbuf(cr,
  //                                 m_image3,
  //                                 x,
  //                                 y);
  // }
  
  // cr->paint(); 
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
