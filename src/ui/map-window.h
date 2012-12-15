// -*- c-basic-offset: 2; -*-
#ifndef MAP_WINDOW_H
#define MAP_WINDOW_H

#include "map-area.h"

#include <iostream>
#include <memory>
#include <string>

#include <gtkmm.h>

#include "controllers/map-controller.h"
#include "controllers/strategy-controller.h"
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
  
  Gtk::VBox vBox;
  
 private:
  Gtk::Image mapImage, strategyImage;
  Gtk::HBox hBox;
  Gtk::Label mapStatus,
    strategyStatus;
  Glib::RefPtr< IAtalUIManager > uiManager_;
  MapController & mc_;
  StrategyController & sc_;
};

#endif // MAP_WINDOW_H
