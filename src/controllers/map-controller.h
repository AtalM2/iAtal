// -*- c-basic-offset: 2; -*-

#ifndef MAP_CONTROLLER_H
#define MAP_CONTROLLER_H

#include "model/map.h"
#include <memory>
#include <string>
#include <gtkmm.h>
#include "tmx/map-loader.h"
#include "ui/map-area.h"


class MapWindow;

class MapController
{
 public:
  static MapController & getInstance()
  {
    static MapController instance;
    return instance;
  }
  
  void setWindow(const std::shared_ptr< MapWindow > & window);

  void loadMap();
  void loadMapFromFile(const Glib::ustring & filename);

  void unloadMap();
  void reloadMap();

  void redraw();

  const std::shared_ptr< iatal::Map > & getMap();
  
 private:
  std::shared_ptr< iatal::Map > map_;
  std::shared_ptr< MapWindow > window_;
  Glib::ustring current_;
  MapController();
  
  // Don't Implement, singleton
  MapController(const MapController &);
  
  // Don't implement, singleton
  void operator=(const MapController &);
};
#endif // MAP_CONTROLLER_H
