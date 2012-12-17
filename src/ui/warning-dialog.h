// -*- c-basic-offset: 2; -*-
#ifndef WARNING_DIALOG_H
#define WARNING_DIALOG_H

#include <gtkmm.h>

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

#endif // WARNING_DIALOG_H
