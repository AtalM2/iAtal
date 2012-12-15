// -*- c-basic-offset: 2; -*-

#ifndef MAP_CONTROLLER_H
#define MAP_CONTROLLER_H

#include <memory>
#include <string>

#include <gtkmm.h>

#include "tmx/map-loader.h"
#include "model/map.h"
#include "ui/maparea.h"

class MapWindow;

class MapController
{
 public:
  static MapController & getInstance()
  {
    static MapController instance;
    return instance;
  }
  
  static std::shared_ptr< Map > loadMap(std::string filepath);

  void setWindow(const std::shared_ptr< MapWindow > & window);

  void loadMap();
  
 private:
  std::shared_ptr< Map > map_;
  std::shared_ptr< MapArea > mapArea_;
  std::shared_ptr< MapWindow > window_;
  MapController();
  MapController(const MapController &); // Don't Implement, singleton
  void operator=(const MapController &); // Don't implement, singleton
};
#endif // MAP_CONTROLLER_H
