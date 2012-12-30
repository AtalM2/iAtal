// -*- c-basic-offset: 2; c-indentation-style: ellemtel; -*-

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

#include "app-controller.h"
#include "ui/iatal-about-dialog.h"
#include "ui/warning-dialog.h"

#include <iostream>

using namespace iatal;

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

void
AppController::quit()
{
  window_->hide();
}

void
AppController::help()
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
