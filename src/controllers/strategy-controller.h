// -*- c-basic-offset: 2; -*-
#ifndef STRATEGY_CONTROLLER_H
#define STRATEGY_CONTROLLER_H

#include <memory>

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
  void nextStep();
  void autoStepsOn();
  void autoStepsOff();
  
 private:
  std::shared_ptr< MapWindow > window_;

  
  std::string strategyPath;
  boost::python::object py_;
  boost::python::object strat;
  boost::python::object isEnded;

  StrategyController();

  // Don't Implement, singleton
  StrategyController(const StrategyController &);

  // Don't Implement, singleton
  void operator=(const StrategyController &); // Don't implement, singleton

};
#endif // STRATEGY_CONTROLLER_H
