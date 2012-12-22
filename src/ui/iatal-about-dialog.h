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

#ifndef IATAL_ABOUT_DIALOG_H
#define IATAL_ABOUT_DIALOG_H

#include <gtkmm.h>

/**
 * About widget for iAtal. Shown on C-h or through the help menu.
 */
class IAtalAboutDialog : public Gtk::AboutDialog
{

public:
  
  /**
   * Constructor.
   * 
   * Sets all the interesting values to build the about dialog.
   */
  IAtalAboutDialog();

  /**
   * Destructor.
   */
  virtual ~IAtalAboutDialog();
  
private:

  /**
   * vector containing the name of the persons that have been involved
   * in the programming of iAtal.
   */
  std::vector< Glib::ustring > authors_,

    /**
     * vector containing the name of the persons that have been involved
     * in the documentation realization.
     */
    documenters_,

    /**
     * vector containing the name of the persons that have been involved
     * in the artworks realization.
     */
    artists_;

};

#endif // IATAL_ABOUT_DIALOG_H
