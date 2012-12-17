// -*- c-basic-offset: 2; -*-
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
