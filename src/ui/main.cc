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

#include "model/map.h"
#include <memory>

#include <boost/program_options.hpp>
#include <gtkmm/application.h>
#include <glibmm/refptr.h>

#include "controllers/app-controller.h"
#include "controllers/map-controller.h"
#include "controllers/strategy-controller.h"
#include "map-window.h"

#include "tmx/map-loader.h"

int on_cmd(const Glib::RefPtr<Gio::ApplicationCommandLine> &,
  Glib::RefPtr<Gtk::Application> &app) {
    app->activate();
    return 0;
}

int
main(int argc, char** argv)
{
  boost::program_options::options_description
    desc("Allowed options");
  desc.add_options()
    ("help,h",
     "Produce help message")

    ("map,m",
     boost::program_options::value< Glib::ustring >(),
     "Set the path to the map to use")

    ("strategy,s",
     boost::program_options::value< Glib::ustring >(),
     "Set the path to the strategy to use. Requires a map to be set too.")
    ;
  boost::program_options::variables_map vm;
  try
    {
      boost::program_options::store(
	boost::program_options::parse_command_line(argc,
						   argv,
						   desc),
	vm);
      boost::program_options::notify(vm);
    }
  catch(...)
    {
      std::cerr << "Incorrect syntax. Use -h to see allowed options."
		<< std::endl;
      return 1;
    }
  if(vm.count("help"))
    {
      std::cout << desc << std::endl;
      return 0;
    }
  if(vm.count("strategy") && !vm.count("map"))
    {
      std::cerr << "Setting a map is required if you set a strategy."
	       << std::endl;
      return 1;
    }

  Glib::RefPtr<Gtk::Application> app =
    Gtk::Application::create(argc,
			     argv,
			     "fr.univnantes.atal.iatal",
			     Gio::APPLICATION_HANDLES_COMMAND_LINE);
  
  app->signal_command_line().connect(
    sigc::bind(sigc::ptr_fun(on_cmd), app), false);

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

      if(vm.count("map"))
	{
	  mc.loadMapFromFile(vm["map"].as< Glib::ustring >());
	  if(vm.count("strategy"))
	    {
	      sc.loadStrategyFromFile(
		vm["strategy"].as< Glib::ustring >());
	    }
	}
      return app->run(*window);
    }
  catch(std::exception e)
    {
      std::cerr << e.what() << std::endl;
      return 1;
    }
}
