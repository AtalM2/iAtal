// -*- c-basic-offset: 2; -*-

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

#ifndef PYTHON_CHOOSER_DIALOG_H
#define PYTHON_CHOOSER_DIALOG_H

#include <gtkmm.h>

/**
 * File chooser dialog tuned for python strategies.
 */
class PythonChooserDialog : public Gtk::FileChooserDialog
{

public:

  /**
   * Constructor.
   */
  PythonChooserDialog();

  /**
   * Destructor.
   */
  virtual ~PythonChooserDialog();
};

#endif // PYTHON_CHOOSER_DIALOG_H
