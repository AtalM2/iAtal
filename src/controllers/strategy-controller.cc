// -*- c-basic-offset: 2; -*-
#include "ui/map-window.h"

#include "controllers/strategy-controller.h"
#include "ui/python-chooser-dialog.h"

#include <iostream>

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
  std::shared_ptr< Map > newMap;
  if(result == Gtk::RESPONSE_OK)
    {
      std::string filename = dialog.get_filename();
    }
  
  // window_->strategyImage.set(Gtk::Stock::YES, Gtk::ICON_SIZE_MENU);
}

void
StrategyController::nextStep()
{
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
