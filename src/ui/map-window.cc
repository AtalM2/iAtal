// -*- c-basic-offset: 2; -*-
#include "map-window.h"

#include <iostream>

#include <boost/lexical_cast.hpp>
#include <gtkmm/stock.h>

#include "ui/python-chooser-dialog.h"
#include "ui/iatal-ui-manager.h"

MapWindow::MapWindow()
  : mapLoaded(false),
    mapImage(Gtk::Stock::NO, Gtk::ICON_SIZE_MENU),
    strategyImage(Gtk::Stock::NO, Gtk::ICON_SIZE_MENU),
    mapStatus("Map loaded:"),
    strategyStatus("Strategy loaded:"),
    uiManager_(IAtalUIManager::create())
{
  set_title("iAtal");
  set_icon_from_file("src/ui/img/icon.png");
  
  // Top hbox handling
  hBox.set_margin_left(5);
  hBox.set_margin_right(5);
  hBox.set_margin_top(5);
  hBox.set_margin_bottom(5);
  hBox.set_spacing(5);
  hBox.pack_start(mapStatus);
  hBox.pack_start(mapImage);
  hBox.pack_start(strategyStatus);
  hBox.pack_start(strategyImage);

  add(vBox); // put a MenuBar at the top of the box and other stuff below it.

  add_accel_group(uiManager_->get_accel_group());
  
  //Get the menubar and toolbar widgets, and add them to a container widget:
  Gtk::Widget* pMenubar = uiManager_->get_widget("/MenuBar");
  if(pMenubar)
    vBox.pack_start(*pMenubar, Gtk::PACK_SHRINK);

  Gtk::Widget* pToolbar = uiManager_->get_widget("/ToolBar") ;
  if(pToolbar)
    vBox.pack_start(*pToolbar, Gtk::PACK_SHRINK);
  
  Glib::RefPtr< Gtk::Action > ac =
    uiManager_->get_action("/ToolBar/StrategyAutoStepsOff");
  
  if(ac)
    ac->set_sensitive(false);
  
  vBox.pack_start(hBox);
  show_all_children();
}


MapWindow::~MapWindow()
{
}

void
MapWindow::setMap(const std::shared_ptr< Map > & map)
{
  area_.setMap(map);
  if(!mapLoaded)
    {
      vBox.pack_start(area_);
      area_.show();
      mapLoaded = true;
    }
}

void
MapWindow::setPathSensitivity(const Glib::ustring & path,
			      bool sensitivity)
{
  uiManager_->setPathSensitivity(path, sensitivity);
}

void
MapWindow::setStrategyStatusOk(bool ok)
{
  if(ok)
    strategyImage.set(Gtk::Stock::YES, Gtk::ICON_SIZE_MENU);
  else
    strategyImage.set(Gtk::Stock::NO, Gtk::ICON_SIZE_MENU);      
}

void
MapWindow::setMapStatusOk(bool ok)
{
  if(ok)
    mapImage.set(Gtk::Stock::YES, Gtk::ICON_SIZE_MENU);
  else
    mapImage.set(Gtk::Stock::NO, Gtk::ICON_SIZE_MENU);    
}

void MapWindow::displayWarning(const Glib::ustring & title,
			       const Glib::ustring & text)
{
  Gtk::MessageDialog warning(*this,
			     title,
			     false,
			     Gtk::MESSAGE_WARNING,
			     Gtk::BUTTONS_CLOSE);
  warning.set_secondary_text(text);
  warning.run();
}
