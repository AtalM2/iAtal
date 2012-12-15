// -*- c-basic-offset: 2; -*-

#ifndef MAP_AREA_H
#define MAP_AREA_H
#include "model/map.h"
#include <memory>

#include <glibmm/ustring.h>
#include <gtkmm/drawingarea.h>
#include <gdkmm/pixbuf.h>


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

#endif // MAP_AREA_H
