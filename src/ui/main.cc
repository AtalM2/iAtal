// -*- c-basic-offset: 2; -*-
#include "model/map.h"
#include <memory>

#include <gtkmm/application.h>
#include <glibmm/refptr.h>

#include "controllers/app-controller.h"
#include "controllers/map-controller.h"
#include "controllers/strategy-controller.h"
#include "map-window.h"

#include "tmx/map-loader.h"

int
main(int argc, char** argv)
{
  Glib::RefPtr<Gtk::Application> app =
    Gtk::Application::create(argc,
                             argv,
                             "org.gtkmm.example");

  MapController & mc = MapController::getInstance();
  StrategyController & sc = StrategyController::getInstance();
  AppController & ac = AppController::getInstance();
  
  try
    {
      auto window =
        std::make_shared< MapWindow >();
      mc.setWindow(window);
      sc.setWindow(window);
      ac.setWindow(window);
      return app->run(*window);
    }
  catch(exception e)
    {
      std::cerr << e.what() << std::endl;
      return 1;
    }
}
