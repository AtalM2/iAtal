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

#include "ui/map-window.h"

#include <iostream>

#include "controllers/app-controller.h"
#include "controllers/map-controller.h"
#include "controllers/strategy-controller.h"
#include "ui/python-chooser-dialog.h"
#include "ui/warning-dialog.h"

StrategyController::StrategyController()
  : autoStepsOn_(false),
    showRobot_(false)
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
      py_["sys"] = boost::python::import("sys");
      exec("sys.path.append('.libs')\n"
           "sys.path.append('src/python')\n",
	   py_);

      exec_file(boost::python::str(filename), py_, py_);

      boost::python::object init = py_["init"];
      boost::python::object rinit = py_["robot_init"];

      isEnded_ = py_["isEnded"];
      strat_ = py_["strat"];

      //initialisation of the robot and map for python
      std::shared_ptr< iatal::Map > newMap =
	MapController::getInstance().getMap();
      init(boost::python::ptr(newMap.get()));
      rinit();

      std::cout << "python initialisé" << std::endl;
      window_->setStrategyStatusOk(true);
      current_ = filename;
      showRobot_ = true;
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
StrategyController::rewind()
{
  if(autoStepsOn_)
    autoStepsOff();
  MapController::getInstance().reloadMap();
  loadStrategyFromFile(current_);
}

bool
StrategyController::shouldShowRobot()
{
  return showRobot_;
}

void
StrategyController::nextStep()
{
  strat();
}

void
StrategyController::autoStepsOn()
{
  sigc::slot<bool> strat = sigc::mem_fun(
    *this,
    &StrategyController::strat);
  timeout_ = Glib::signal_timeout().connect(
    strat,
    300);
  window_->setPathSensitivity(
    "/ToolBar/StrategyAutoStepsOn",
    false);
  window_->setPathSensitivity(
    "/ToolBar/StrategyAutoStepsOff",
    true);
  autoStepsOn_ = true;
}

void
StrategyController::autoStepsOff()
{
  timeout_.disconnect();
  window_->setPathSensitivity(
    "/ToolBar/StrategyAutoStepsOn",
    true);
  window_->setPathSensitivity(
    "/ToolBar/StrategyAutoStepsOff",
    false);
  autoStepsOn_ = false;
}

void
StrategyController::endStrategy(bool onError)
{
  if(autoStepsOn_)
    autoStepsOff();
  if(onError)
    {
      window_->setStrategyStatusOk(false);
      showRobot_ = false;
    }
  else
    {
      window_->setPathSensitivity(
	"/ToolBar/StrategyNextStep",
	false);
      window_->setPathSensitivity(
	"/ToolBar/StrategyAutoStepsOn",
	false);
      window_->setPathSensitivity(
	"/ToolBar/StrategyAutoStepsOff",
	false);
    }
}

void
StrategyController::setWindow(const std::shared_ptr< MapWindow > & window)
{
  window_ = window;
}

bool
StrategyController::strat()
{
  if (!isEnded())
    {
      try
	{
	  strat_();
      MapController::getInstance().redraw();
	}
      catch (const boost::python::error_already_set & e)
	{
	  AppController::displayWarning(
	    "Strategy failed.",
	    "A problem occured while running the strategy.");
	  PyErr_Print();
	  endStrategy(true);
	  return false;
	}
      if(!isEnded())
	{
	  return true;
	}
    }
  endStrategy(false);
  return false;
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
    endStrategy(true);
    PyErr_Print();
    return true;
  }
  return boost::python::extract<bool>(endedPy);
}
