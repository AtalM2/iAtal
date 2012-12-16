// -*- c-basic-offset: 2; -*-
#include "map-window.h"

MapWindow::MapWindow()
  : mapLoaded_(false),
    uiManager_(IAtalUIManager::create())
{
  set_title("iAtal");
  set_icon_from_file("src/ui/img/icon.png");
  
  add_accel_group(uiManager_->get_accel_group());
  
  
  vBox_.pack_start(uiManager_->getMenuBar(),
		   Gtk::PACK_SHRINK);

  vBox_.pack_start(uiManager_->getToolBar(),
		   Gtk::PACK_SHRINK);

  vBox_.pack_start(hBox_);

  add(vBox_);

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
		     ok);
  setPathSensitivity("/ToolBar/StrategyAutoStepsOff",
		     false);
  setPathSensitivity("/ToolBar/StrategyNextStep",
		     ok);
}

void
MapWindow::setMapStatusOk(bool ok)
{
  hBox_.setMapStatusOk(ok);
  setPathSensitivity("/ToolBar/FileOpenStrategy",
		     ok);
}
