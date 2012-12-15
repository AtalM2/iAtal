// -*- c-basic-offset: 2; -*-
#ifndef IATAL_ABOUT_DIALOG_H
#define IATAL_ABOUT_DIALOG_H

#include <gtkmm.h>

class IAtalAboutDialog : public Gtk::AboutDialog
{

 public:
  IAtalAboutDialog();
  virtual ~IAtalAboutDialog();
  
 private:
  std::vector< Glib::ustring > authors_,
    documenters_,
    artists_;

};

#endif // IATAL_ABOUT_DIALOG_H
