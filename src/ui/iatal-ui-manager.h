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

#ifndef IATAL_UI_MANAGER_H
#define IATAL_UI_MANAGER_H

#include <gtkmm.h>

/**
 * Menu and toolbar handling class for iAtal.
 */
class IAtalUIManager : public Gtk::UIManager
{

public:
  /**
   * Glib style create, returns a RefPtr containing our newly made
   * objetc. It's the only method that should call the constructor to
   * ensure the efficiency of the RefPtr.
   */
  static Glib::RefPtr< IAtalUIManager > create();
  
  /**
   * Destructor.
   */
  virtual ~IAtalUIManager();
  
  /**
   * Returns the widget that corresponds to the MenuBar. Convenient
   * method since it's created from a string and isn't accessible in a
   * typesafe manner.
   */
  Gtk::Widget & getMenuBar();
  
  /**
   * Returns the widget that corresponds to the ToolBar. Convenient
   * method since it's created from a string and isn't accessible in a
   * typesafe manner.
   */
  Gtk::Widget & getToolBar();
  
  /**
   * Sets a certain item's sensitivity. Allows for quick locking of
   * the menu and toolbar items.
   * 
   * \param path The path in the menu hierarchy of the item to
   * process.
   * 
   * \param sensitivity The action to perform: enable or disable.
   */
  void setPathSensitivity(const Glib::ustring & path,
                          bool sensitivity);

protected:
  /**
   * Should never be called by another method than IAtalUIManager::create().
   */
  IAtalUIManager();

};

#endif // IATAL_UI_MANAGER_H
