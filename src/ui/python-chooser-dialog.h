// -*- c-basic-offset: 2; -*-
#ifndef PYTHON_CHOOSER_DIALOG_H
#define PYTHON_CHOOSER_DIALOG_H

#include <gtkmm.h>

class PythonChooserDialog : public Gtk::FileChooserDialog
{

public:
  PythonChooserDialog();
  virtual ~PythonChooserDialog();
};

#endif // PYTHON_CHOOSER_DIALOG_H
