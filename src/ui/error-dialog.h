// -*- c-basic-offset: 2; -*-
#ifndef ERROR_DIALOG_H
#define ERROR_DIALOG_H

#include <gtkmm.h>

class ErrorDialog : public Gtk::MessageDialog
{

 public:
  ErrorDialog(Gtk::Window & parent,
	      const Glib::ustring & title,
	      const Glib::ustring & text);
  virtual ~ErrorDialog();
  
};

#endif // ERROR_DIALOG_H
