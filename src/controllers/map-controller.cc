// -*- c-basic-offset: 2; -*-
#include "map-controller.h"

#include <iostream>

#include "ui/map-window.h"
#include "ui/map-area.h"
#include "ui/tmx-chooser-dialog.h"

MapController::MapController()
{
  
}

void
MapController::loadMap()
{
  TmxChooserDialog dialog;
  dialog.set_transient_for(*window_);

  //Show the dialog and wait for a user response:
  int result = dialog.run();

  //Handle the response:
  std::shared_ptr< Map > newMap;
  if(result == Gtk::RESPONSE_OK)
    {
      std::string filename = dialog.get_filename();

      try
	{
	    newMap = MapLoader::loadTmx(filename);
	}
      catch(const exception & e)
	{
	  dialog.hide();
	  window_->displayWarning("Map loading failed.", e.what());
	  return;
	}
      catch(const Glib::Exception & e)
	{
	  dialog.hide();
	  window_->displayWarning("Map loading failed.", e.what());
	  return;
	}
      catch(...)
	{
	  dialog.hide();
	  window_->displayWarning(
	    "Map loading failed.",
	    "Please see the supported format in the manual");
	  return;
	}
    }
  window_->setMap(newMap);
  window_->resize(1, 1);
  window_->setMapStatusOk(true);
  window_->setPathSensitivity("/ToolBar/FileOpenStrategy", true);
  map_.swap(newMap);
}

void
MapController::setWindow(const std::shared_ptr< MapWindow > & window)
{
  window_ = window;
}
