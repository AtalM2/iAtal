// -*- c-basic-offset: 2; -*-

//  Copyright (C) 2012

// This file is part of iAtal.

// iAtal is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// iAtal is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with iAtal.  If not, see <http://www.gnu.org/licenses/>.

#include "map-window.h"

using namespace iatal;

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
  setPathSensitivity("/ToolBar/StrategyRewind",
		     ok);
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
