// -*- c-basic-offset: 2; -*-

#include "ui/map-window.h"

#include <iostream>

#include "controllers/app-controller.h"
#include "controllers/map-controller.h"
#include "controllers/strategy-controller.h"
#include "ui/python-chooser-dialog.h"
#include "ui/warning-dialog.h"

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
    //loads the python, but doesn't let it handle signals.
    Py_InitializeEx(0);

    boost::python::object main = boost::python::import("__main__");
    py_ = main.attr("__dict__");

    // Makes visible the libraries exposing the C++ API and the python classes
    exec("import sys\n"
         "sys.path.append('.libs')\n"
         "sys.path.append('src/python')\n",
         py_);

    exec_file(boost::python::str(filename), py_, py_);

    boost::python::object init = py_["init"];
    boost::python::object rinit = py_["robot_init"];

    isEnded_ = py_["isEnded"];
    strat_ = py_["strat"];

    //initialisation of the robot and map for python
    std::shared_ptr< Map > newMap =
      MapController::getInstance().getMap();
    init(boost::python::ptr(newMap.get()));
    rinit();

    std::cout << "python initialisé" << std::endl;
    window_->setStrategyStatusOk(true);
  }
  catch(const std::exception & e)
  {
    std::ostringstream oss;
    oss << "There has been an exception during the "
        << "loading of the strategy file:"
        << std::endl
        << e.what()
        << std::endl;
    AppController::displayWarning(
      "Strategy not loaded.",
      oss.str());
    window_->setStrategyStatusOk(false);
    return;
  }
  catch(const boost::python::error_already_set & e)
  {
    AppController::displayWarning(
      "Strategy not loaded.",
      "The strategy set isn't coherent with the map loaded.");
    window_->setStrategyStatusOk(false);
    PyErr_Print();
    return;
  }
}

void
StrategyController::nextStep()
{
  strat();
}

void
StrategyController::autoStepsOn()
{
  while(strat());
}

void
StrategyController::autoStepsOff()
{

}

void
StrategyController::setWindow(const std::shared_ptr< MapWindow > & window)
{
  window_ = window;
}

void
StrategyController::unloadStrategy()
{
  window_->setStrategyStatusOk(false);
}

bool
StrategyController::strat()
{
  if (!isEnded())
  {
    try {
      strat_();
    } catch (const boost::python::error_already_set & e) {
      AppController::displayWarning(
        "Strategy failed.",
        "A problem occured while running the strategy.");
      window_->setStrategyStatusOk(false);
      PyErr_Print();
      return false;
    }
  }
  return true;
}

bool
StrategyController::isEnded()
{
  boost::python::object endedPy;
  try {
    endedPy = isEnded_();
  } catch (const boost::python::error_already_set & e) {
    AppController::displayWarning(
      "Strategy failed.",
      "A problem occured while testing the end of the strategy.");
    window_->setStrategyStatusOk(false);
    PyErr_Print();
    return true;
  }
  return boost::python::extract<bool>(endedPy);
}
