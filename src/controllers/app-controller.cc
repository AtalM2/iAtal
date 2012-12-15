// -*- c-basic-offset: 2; -*-
#include "ui/map-window.h"

#include "app-controller.h"
#include "ui/iatal-about-dialog.h"

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
  IAtalAboutDialog dialog;
  dialog.run();
}

void
AppController::setWindow(const std::shared_ptr< MapWindow > & window)
{
  window_ = window;
}
