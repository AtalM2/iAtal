// -*- c-basic-offset: 2; -*-
#include "map-controller.h"

#include <iostream>

#include "ui/mapwindow.h"

MapController::MapController()
{
  
}

void
MapController::loadMap()
{
  Gtk::FileChooserDialog dialog(
    "Please choose a map file to load",
    Gtk::FILE_CHOOSER_ACTION_OPEN);
  dialog.set_transient_for(*window_);

  //Add response buttons the the dialog:
  dialog.add_button(Gtk::Stock::CANCEL,
		    Gtk::RESPONSE_CANCEL);
  dialog.add_button(Gtk::Stock::OPEN,
		    Gtk::RESPONSE_OK);

  //Add filters, so that only certain file types can be selected:
  Glib::RefPtr<Gtk::FileFilter> filter_tmx =
    Gtk::FileFilter::create();
  filter_tmx->set_name("TMX files");
  filter_tmx->add_pattern("*.tmx");
  dialog.add_filter(filter_tmx);
  
  Glib::RefPtr<Gtk::FileFilter> filter_any =
    Gtk::FileFilter::create();
  filter_any->set_name("Any files");
  filter_any->add_pattern("*");
  dialog.add_filter(filter_any);

  //Show the dialog and wait for a user response:
  int result = dialog.run();

  //Handle the response:
  if(result == Gtk::RESPONSE_OK)
    {
      std::cout << "Open clicked." << std::endl;
      
      //Notice that this is a std::string, not a Glib::ustring.
      std::string filename = dialog.get_filename();
      try
	{
	  std::shared_ptr< Map > newMap =
	    MapLoader::loadTmx(filename);
	}
      catch(const exception & e)
	{
	  dialog.hide();
	  window_->displayWarning("Map loading failed.", e.what());
	}
      catch(const Glib::Exception & e)
	{
	  dialog.hide();
	  window_->displayWarning("Map loading failed.", e.what());
	}
      catch(...)
	{
	  dialog.hide();
	  window_->displayWarning(
	    "Map loading failed.",
	    "Please see the supported format in the manual");
	}
      std::cout << "File selected: " <<  filename << std::endl;
    }
}

void
MapController::setWindow(const std::shared_ptr< MapWindow > & window)
{
  window_ = window;
}
