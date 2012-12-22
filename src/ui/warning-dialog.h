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

#ifndef WARNING_DIALOG_H
#define WARNING_DIALOG_H

#include <gtkmm.h>

namespace iatal
{
  /**
   * Message dialog tuned to display a warning.
   */
  class WarningDialog : public Gtk::MessageDialog
  {

  public:
    /**
     * Constructor.
     * 
     * \param title The title of the warning to display. Should be
     * short.
     * 
     * \param text The text of the warning to display. Should be
     * informative and helping to spot where the error came from and
     * what is the next step.
     */
    WarningDialog(const Glib::ustring & title,
		  const Glib::ustring & text);
    /**
     * Destructor.
     */
    virtual ~WarningDialog();
  
  };
}

#endif // WARNING_DIALOG_H
