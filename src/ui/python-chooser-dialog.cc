// -*- c-basic-offset: 2; -*-
#include "ui/python-chooser-dialog.h"

PythonChooserDialog::PythonChooserDialog()
  : Gtk::FileChooserDialog("Please choose a strategy file to load",
			   Gtk::FILE_CHOOSER_ACTION_OPEN)
{

  //Add response buttons the the dialog:
  add_button(Gtk::Stock::CANCEL,
	     Gtk::RESPONSE_CANCEL);
  add_button(Gtk::Stock::OPEN,
	     Gtk::RESPONSE_OK);

  //Add filters, so that only certain file types can be selected:
  Glib::RefPtr<Gtk::FileFilter> filter_py =
    Gtk::FileFilter::create();
  filter_py->set_name("Python files");
  filter_py->add_pattern("*.py");
  add_filter(filter_py);
  
  Glib::RefPtr<Gtk::FileFilter> filter_any =
    Gtk::FileFilter::create();
  filter_any->set_name("Any files");
  filter_any->add_pattern("*");
  add_filter(filter_any);
}

PythonChooserDialog::~PythonChooserDialog()
{
  
}
