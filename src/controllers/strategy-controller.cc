// -*- c-basic-offset: 2; -*-

#include "ui/map-window.h"

#include <iostream>

#include "controllers/map-controller.h"
#include "controllers/strategy-controller.h"
#include "ui/python-chooser-dialog.h"

StrategyController::StrategyController()
{

}

void
StrategyController::loadStrategy()
{
    PythonChooserDialog dialog;
    dialog.set_transient_for(*window_);

    //Show the dialog and wait for a user response:
    int result = dialog.run();

    //Handle the response:
    if(result != Gtk::RESPONSE_OK)
      {
	return;
      }

    loadStrategyFromFile(dialog.get_filename());

}

void
StrategyController::loadStrategyFromFile(const std::string & filename)
{
  try
    {
      //loads the python
      Py_Initialize();
      boost::python::object main = boost::python::import("__main__");
      py_ = main.attr("__dict__");

      exec_file(boost::python::str(filename), py_, py_);

      boost::python::object init = py_["init"];
      boost::python::object rinit = py_["robot_init"];

      isEnded = py_["isEnded"];
      strat = py_["strat"];

      //initialisation of the robot and map for python
      std::shared_ptr<Map> newMap = MapController::getInstance().getMap();
      init(boost::python::ptr(newMap.get()));
      rinit();

      std::cout << "python initialisé" << std::endl;
      window_->setStrategyStatusOk(true);
    }
  catch (boost::python::error_already_set)
    {
      std::cout << "Incoherent file. The python strategy has not been loaded"
		<< std::endl;
      window_->setStrategyStatusOk(false);
      PyErr_Print();
    }
}

void
StrategyController::nextStep()
{
  strat();
  std::cout << "<appel à nextStep() du controlleur stratégie/>"
	    << std::endl;
}

void
StrategyController::autoStepsOn()
{
  std::cout << "<appel à autoStepsOn() du controlleur stratégie/>"
	    << std::endl;
}

void
StrategyController::autoStepsOff()
{
  std::cout << "<appel à autoStepsOff() du controlleur stratégie/>"
	    << std::endl;
}

void
StrategyController::setWindow(const std::shared_ptr< MapWindow > & window)
{
  window_ = window;
}
