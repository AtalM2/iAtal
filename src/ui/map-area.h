// -*- c-basic-offset: 2; -*-
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
  void setMap(const std::shared_ptr< Map > & map);

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
  std::shared_ptr< Map > map_;
};

#endif // MAP_AREA_H
