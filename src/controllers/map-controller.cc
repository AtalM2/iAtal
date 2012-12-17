// -*- c-basic-offset: 2; -*-
#include "map-controller.h"

#include <iostream>

#include "controllers/app-controller.h"
#include "ui/map-window.h"
#include "ui/map-area.h"
#include "ui/tmx-chooser-dialog.h"
#include "ui/warning-dialog.h"

MapController::MapController()
  : current_("")
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
  if(result != Gtk::RESPONSE_OK)
    {
      return;
    }
  
  loadMapFromFile(dialog.get_filename());
  
}

void
MapController::loadMapFromFile(const Glib::ustring & filename)
{
  std::shared_ptr< Map > newMap;
  try
    {
      newMap = MapLoader::loadTmx(filename);
    }
  catch(const exception & e)
    {
      AppController::displayWarning("Map loading failed.",
				    e.what());
      unloadMap();
      return;
    }
  catch(const Glib::Exception & e)
    {
      AppController::displayWarning("Map loading failed.",
				    e.what());
      unloadMap();
      return;
    }
  catch(...)
    {
      AppController::displayWarning(
	"Map loading failed.",
	"Please see the supported format in the manual");
      unloadMap();
      return;
    }
  window_->setMap(newMap);
  window_->resize(1, 1);
  window_->setMapStatusOk(true);
  // Now we don't know if the current strategy is ok or not.
  window_->setStrategyStatusOk(false);
  map_.swap(newMap);
  current_ = filename;
}

const std::shared_ptr<Map> &
MapController::getMap()
{
  return map_;
}

void
MapController::setWindow(const std::shared_ptr< MapWindow > & window)
{
  window_ = window;
}

void
MapController::unloadMap()
{
  window_->setMapStatusOk(false);
  std::shared_ptr< Map > newMap = std::make_shared< Map >();
  window_->setMap(newMap);
}

void
MapController::reloadMap()
{
  if(current_ != "")
    loadMapFromFile(current_);
}
