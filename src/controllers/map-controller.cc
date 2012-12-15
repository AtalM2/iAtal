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
  map_.swap(newMap);
  auto newArea = std::make_shared< MapArea >(map_);
  newArea->set_margin_left(5);
  newArea->set_margin_right(5);
  newArea->set_margin_top(5);
  newArea->set_margin_bottom(5);
  if(mapArea_.get())
    window_->vBox.remove(*mapArea_);
  window_->vBox.pack_start(*newArea);
  window_->resize(1, 1);
  newArea->show();
  mapArea_.swap(newArea);
  window_->mapImage.set(Gtk::Stock::YES, Gtk::ICON_SIZE_MENU);
}

void
MapController::setWindow(const std::shared_ptr< MapWindow > & window)
{
  window_ = window;
}
