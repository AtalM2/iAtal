// -*- c-basic-offset: 2; -*-

#include <iostream>

#include <gtkmm/application.h>

#include "map-loader.h"

int
main(int argc, char *argv[])
{
  Glib::RefPtr<Gtk::Application> app =
    Gtk::Application::create(argc,
                             argv,
                             "fr.univnantes.atal");
  try
    {
      MapLoader::loadTmx("src/tmx/resources/map.tmx");
    }
  catch(std::string s)
    {
      std::cout << s << std::endl;
    }
  return 0;
}
