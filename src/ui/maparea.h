// -*- c-basic-offset: 2; -*-

#ifndef MAPAREA_H
#define MAPAREA_H

#include <memory>

#include <glibmm/ustring.h>
#include <gtkmm/drawingarea.h>
#include <gdkmm/pixbuf.h>

#include "model/map.h"
#include "model/tileset.h"

class MapArea : public Gtk::DrawingArea
{

 public:
  MapArea(const std::shared_ptr< Map > & map);
  /* void move(int dx, int dy); */
  virtual ~MapArea();

 protected:
  virtual bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);
  
 private:
  std::shared_ptr< Map > map_;
};

#endif // MAPAREA_H
