// -*- c-basic-offset: 2; -*-
#include "ui/map-window.h"

#include "app-controller.h"
#include "ui/error-dialog.h"
#include "ui/iatal-about-dialog.h"
#include "ui/warning-dialog.h"

#include <iostream>

AppController::AppController()
{
  
}

void
AppController::displayError(const Glib::ustring & title,
			    const Glib::ustring & text)
{
  ErrorDialog(*window_,
	      title,
	      text);
}

void
AppController::displayWarning(const Glib::ustring & title,
			      const Glib::ustring & text)
{
  WarningDialog(*window_,
		title,
		text);
}

void AppController::displayAbout()
{
  IAtalAboutDialog();
}

void AppController::quit()
{
  window_->hide();
}

void
AppController::setWindow(const std::shared_ptr< MapWindow > & window)
{
  window_ = window;
}
