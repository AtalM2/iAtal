// -*- c-basic-offset: 2; -*-

#include <memory>

#include <gtkmm/application.h>
#include <glibmm/refptr.h>

#include "controllers/strategy-controller.h"
#include "mapwindow.h"
#include "model/map.h"
#include "tmx/map-loader.h"

int
main(int argc, char** argv)
{
  Glib::RefPtr<Gtk::Application> app =
    Gtk::Application::create(argc,
                             argv,
                             "org.gtkmm.example");
  try
    {
      
      std::shared_ptr< Map > map(
	new Map(MapLoader::loadTmx("src/tmx/resources/map.tmx")));
StrategyController sc;
MapWindow window(map,
		   sc);
      
      return app->run(window);
    }
  catch(exception e)
    {
      std::cerr << e.what() << std::endl;
      return 1;
    }
}
