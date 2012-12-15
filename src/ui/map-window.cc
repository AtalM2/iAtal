// -*- c-basic-offset: 2; -*-
#include "map-window.h"

#include <iostream>

#include <boost/lexical_cast.hpp>
#include <gtkmm/stock.h>

#include "ui/python-chooser-dialog.h"
#include "ui/iatal-ui-manager.h"

MapWindow::MapWindow()
  : mapLoaded_(false),
    uiManager_(IAtalUIManager::create())
{
  set_title("iAtal");
  set_icon_from_file("src/ui/img/icon.png");
  
  // Top hbox handling

  add(vBox_); // put a MenuBar at the top of the box and other stuff below it.

  add_accel_group(uiManager_->get_accel_group());
  
  //Get the menubar and toolbar widgets, and add them to a container widget:
  Gtk::Widget* pMenubar = uiManager_->get_widget("/MenuBar");
  if(pMenubar)
    vBox_.pack_start(*pMenubar, Gtk::PACK_SHRINK);

  Gtk::Widget* pToolbar = uiManager_->get_widget("/ToolBar") ;
  if(pToolbar)
    vBox_.pack_start(*pToolbar, Gtk::PACK_SHRINK);
  
  vBox_.pack_start(hBox_);
  show_all_children();
}


MapWindow::~MapWindow()
{
}

void
MapWindow::setMap(const std::shared_ptr< Map > & map)
{
  area_.setMap(map);
  if(!mapLoaded_)
    {
      vBox_.pack_start(area_);
      area_.show();
      mapLoaded_ = true;
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
  hBox_.setStrategyStatusOk(ok);
  setPathSensitivity("/ToolBar/StrategyAutoStepsOn",
		     true);
  setPathSensitivity("/ToolBar/StrategyAutoStepsOff",
		     false);
  setPathSensitivity("/ToolBar/StrategyNextStep",
		     true);
}

void
MapWindow::setMapStatusOk(bool ok)
{
  hBox_.setMapStatusOk(ok);
  setPathSensitivity("/ToolBar/FileOpenStrategy",
		     true);
}
