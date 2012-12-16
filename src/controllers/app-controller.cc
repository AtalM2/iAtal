// -*- c-basic-offset: 2; -*-
#include "ui/map-window.h"

#include "app-controller.h"
#include "ui/iatal-about-dialog.h"
#include "ui/warning-dialog.h"

#include <iostream>

AppController::AppController()
{
  
}

int
AppController::displayWarning(const Glib::ustring & title,
			      const Glib::ustring & text)
{
  WarningDialog dialog(title,
		       text);
  return dialog.run();
}

void AppController::quit()
{
  window_->hide();
}

void AppController::help()
{
  IAtalAboutDialog dialog;
}

void
AppController::setWindow(const std::shared_ptr< MapWindow > & window)
{
  window_ = window;
}
const std::shared_ptr< MapWindow > &
AppController::getWindow()
{
  return window_;
}
