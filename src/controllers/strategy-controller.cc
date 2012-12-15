// -*- c-basic-offset: 2; -*-
#include "strategy-controller.h"

#include <iostream>

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
