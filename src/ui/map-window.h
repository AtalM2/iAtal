// -*- c-basic-offset: 2; -*-
#ifndef MAP_WINDOW_H
#define MAP_WINDOW_H

#include "map-area.h"

#include <iostream>
#include <memory>
#include <string>

#include <gtkmm.h>

#include "ui/iatal-ui-manager.h"

class MapWindow : public Gtk::Window
{

public:
  MapWindow();
  virtual ~MapWindow();
  void displayWarning(const Glib::ustring & title,
		      const Glib::ustring & text);
  
  void setMapStatusOk(bool ok);
  void setStrategyStatusOk(bool ok);
  
  void setMap(const std::shared_ptr< Map > & map);
  
  void setPathSensitivity(const Glib::ustring & path,
			  bool sensitivity);
  
 private:
  bool mapLoaded;
  Gtk::VBox vBox;
  Gtk::Image mapImage, strategyImage;
  Gtk::Label mapStatus, strategyStatus;
  Gtk::HBox hBox;
  Glib::RefPtr< IAtalUIManager > uiManager_;
  MapArea area_;
};

#endif // MAP_WINDOW_H
