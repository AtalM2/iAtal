#ifndef MAPAREA_H
#define MAPAREA_H

#include <glibmm/ustring.h>
#include <gtkmm/drawingarea.h>
#include <gdkmm/pixbuf.h>

class MapArea : public Gtk::DrawingArea
{

public:
  MapArea(Glib::ustring file_path1,
	  Glib::ustring file_path2,
	  Glib::ustring file_path3);
  void move(int dx, int dy);
  virtual ~MapArea();

protected:

  virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);

  Glib::RefPtr<Gdk::Pixbuf> m_image1,
    m_image2,
    m_image3;
  int x, y;

};

#endif // MAPAREA_H
