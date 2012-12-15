// -*- c-basic-offset: 2; -*-
#include "ui/map-window.h"

#include "app-controller.h"

#include <iostream>

AppController::AppController()
{
  
}

void AppController::quit()
{
  window_->hide();
}

void AppController::help()
{
  
}

void
AppController::setWindow(const std::shared_ptr< MapWindow > & window)
{
  window_ = window;
}
