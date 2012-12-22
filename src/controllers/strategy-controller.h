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

#ifndef STRATEGY_CONTROLLER_H
#define STRATEGY_CONTROLLER_H

#include <memory>
#include <string>

#include <glibmm/ustring.h>

class MapWindow;

class StrategyController
{
 public:
  static StrategyController & getInstance()
  {
    static StrategyController instance;
    return instance;
  }
  
  void setWindow(const std::shared_ptr< MapWindow > & window);

  void loadStrategy();
  void loadStrategyFromFile(const std::string & filename);

  void endStrategy(bool onError);
  
  void rewind();
  void nextStep();
  void autoStepsOn();
  void autoStepsOff();
  
  bool shouldShowRobot();
  
 private:
  std::shared_ptr< MapWindow > window_;
  sigc::connection timeout_;
  Glib::ustring current_;
  bool autoStepsOn_,
    showRobot_;

  boost::python::object py_;
  boost::python::object strat_;
  boost::python::object isEnded_;

  StrategyController();

  bool strat();
  bool isEnded();

  // Don't Implement, singleton
  StrategyController(const StrategyController &);

  // Don't Implement, singleton
  void operator=(const StrategyController &); // Don't implement, singleton

};
#endif // STRATEGY_CONTROLLER_H
