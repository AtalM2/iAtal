// -*- c-basic-offset: 2; -*-
#ifndef WARNING_DIALOG_H
#define WARNING_DIALOG_H

#include <gtkmm.h>

class WarningDialog : public Gtk::MessageDialog
{

 public:
  WarningDialog(const Glib::ustring & title,
		const Glib::ustring & text);
  virtual ~WarningDialog();
  
};

#endif // WARNING_DIALOG_H
