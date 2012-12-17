// -*- c-basic-offset: 2; -*-
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
