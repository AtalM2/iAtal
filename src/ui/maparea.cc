#include <cairomm/context.h>
#include <gdkmm/general.h> // set_source_pixbuf()
#include <gdkmm/pixbufanimation.h>
#include <glibmm/fileutils.h>
#include <iostream>

#include "maparea.h"

MapArea::MapArea(Glib::ustring file_path1,
		 Glib::ustring file_path2,
		 Glib::ustring file_path3)
  : x(3),
    y(3)
{
  try
    {
      m_image1 = Gdk::Pixbuf::create_from_file(file_path1);
      m_image2 = Gdk::Pixbuf::create_from_file(file_path2);
      m_image3 = Gdk::Pixbuf::create_from_file(file_path3);
    }
  catch (const Glib::FileError& ex)
    {
      std::cerr << "FileError: " << ex.what() << std::endl;
    }
  catch (const Gdk::PixbufError& ex)
    {
      std::cerr << "PixbufError: " << ex.what() << std::endl;
    }

  set_size_request(500, 500);
}

MapArea::~MapArea()
{
}

bool MapArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
  if (!m_image1)
    return false;
  bool even = true;
  for (int i = 0; i < 500; i += 20)
      for (int j = 0; j < 500; j += 10)
	{
	  Gdk::Cairo::set_source_pixbuf(cr,
					even ? m_image1 : m_image2,
					i,
					j);
	  cr->paint();
	  
	  Gdk::Cairo::set_source_pixbuf(cr,
					even ? m_image2 : m_image1,
					i + 10,
					j);
	  cr->paint(); 
	  even = !even;
	}
  Gdk::Cairo::set_source_pixbuf(cr,
				m_image3,
				x,
				y);
  cr->paint(); 
  
  return true;
}

void
MapArea::move(int dx, int dy)
{
  const Cairo::RectangleInt rect_start = {x, y, 10, 10};
  x += dx;
  y += dy;
  const Cairo::RectangleInt  rect_end = {x, y, 10, 10};
  const std::vector< Cairo::RectangleInt > rect_vector {rect_start, rect_end};
  Cairo::RefPtr< Cairo::Region > region = Cairo::Region::create(rect_vector);
  queue_draw_region(region);
}
