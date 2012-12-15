#include "warning-dialog.h"

WarningDialog::WarningDialog(
  Gtk::Window & parent,
  const Glib::ustring & title,
  const Glib::ustring & text)
  : Gtk::MessageDialog(parent,
		       title,
		       false,
		       Gtk::MESSAGE_WARNING,
		       Gtk::BUTTONS_CLOSE)

{
  set_secondary_text(text);
  run();
}

WarningDialog::~WarningDialog()
{
  
}
