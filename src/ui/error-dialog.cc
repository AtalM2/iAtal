#include "error-dialog.h"

ErrorDialog::ErrorDialog(
  Gtk::Window & parent,
  const Glib::ustring & title,
  const Glib::ustring & text)
  : Gtk::MessageDialog(parent,
		       title,
		       false,
		       Gtk::MESSAGE_ERROR,
		       Gtk::BUTTONS_CLOSE)

{
  set_secondary_text(text);
  run();
}

ErrorDialog::~ErrorDialog()
{
  
}
