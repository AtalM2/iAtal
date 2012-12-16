// -*- c-basic-offset: 2; -*-
#ifndef IATAL_ABOUT_DIALOG_H
#define IATAL_ABOUT_DIALOG_H

#include <gtkmm.h>
class IAtalAboutDialog : public Gtk::AboutDialog
{

 public:
  
  /**
   * Constructor.
   * 
   * Sets all the interesting values to build the about dialog.
   */
  IAtalAboutDialog();

  /**
   * Destructor.
   */
  virtual ~IAtalAboutDialog();
  
 private:

  /**
   * vector containing the name of the persons that have been involved
   * in the programming of iAtal.
   */
  std::vector< Glib::ustring > authors_,

  /**
   * vector containing the name of the persons that have been involved
   * in the documentation realization.
   */
    documenters_,

  /**
   * vector containing the name of the persons that have been involved
   * in the artworks realization.
   */
    artists_;

};

#endif // IATAL_ABOUT_DIALOG_H
