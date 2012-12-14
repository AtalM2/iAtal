// -*- c-basic-offset: 2; -*-

#ifndef MAPWINDOW_H
#define MAPWINDOW_H

#include <iostream>
#include <memory>
#include <string>

#include <glibmm/ustring.h>
#include <gtkmm/window.h>
#include <gtkmm/fixed.h>
#include <gtkmm/box.h>
#include <gtkmm/button.h>
#include <gtkmm/entry.h>

#include "maparea.h"

class MapWindow : public Gtk::Window
{

public:
  MapWindow(const std::shared_ptr< Map > & map);
  virtual ~MapWindow();
  
protected:
  void on_button_clicked();
  Gtk::Fixed layout;
  Gtk::HBox hbox;
  Gtk::Button button;
  Gtk::Entry dx,
    dy;
  Gtk::Label dxl,
    dyl;
  MapArea area;
};

#endif // MAPWINDOW_H
