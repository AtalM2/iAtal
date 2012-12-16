#include "warning-dialog.h"

WarningDialog::WarningDialog(
  const Glib::ustring & title,
  const Glib::ustring & text)
  : Gtk::MessageDialog(title,
		       false,
		       Gtk::MESSAGE_WARNING,
		       Gtk::BUTTONS_CLOSE)

{
  set_secondary_text(text);
}

WarningDialog::~WarningDialog()
{
  
}
