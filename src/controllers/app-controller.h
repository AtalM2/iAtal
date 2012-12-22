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

#ifndef APP_CONTROLLER_H
#define APP_CONTROLLER_H

#include <memory>

#include <gtkmm.h>

class MapWindow;

class AppController
{
public:
  static AppController & getInstance()
  {
    static AppController instance;
    return instance;
  }
  
  void setWindow(const std::shared_ptr< MapWindow > & window);
  const std::shared_ptr< MapWindow > & getWindow();

  static int displayWarning(const Glib::ustring & title,
                            const Glib::ustring & text);
  
  void quit();
  void help();
  
private:
  std::shared_ptr< MapWindow > window_;
  
  AppController();
  
  // Don't Implement, singleton
  AppController(const AppController &);
  
  // Don't implement, singleton
  void operator=(const AppController &);
};
#endif // APP_CONTROLLER_H
