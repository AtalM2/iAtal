// -*- c-basic-offset: 2; -*-
#include "ui/tmx-chooser-dialog.h"

TmxChooserDialog::TmxChooserDialog()
  : Gtk::FileChooserDialog("Please choose a map file to load",
			   Gtk::FILE_CHOOSER_ACTION_OPEN)
{
  //Add response buttons the the dialog:
  add_button(Gtk::Stock::CANCEL,
	     Gtk::RESPONSE_CANCEL);
  add_button(Gtk::Stock::OPEN,
	     Gtk::RESPONSE_OK);
  
  //Add filters, so that only certain file types can be selected:
  Glib::RefPtr<Gtk::FileFilter> filter_tmx =
    Gtk::FileFilter::create();
  filter_tmx->set_name("TMX files");
  filter_tmx->add_pattern("*.tmx");
  add_filter(filter_tmx);
  
  Glib::RefPtr<Gtk::FileFilter> filter_any =
    Gtk::FileFilter::create();
  filter_any->set_name("Any files");
  filter_any->add_pattern("*");
  add_filter(filter_any); 
}

TmxChooserDialog::~TmxChooserDialog()
{
  
}
