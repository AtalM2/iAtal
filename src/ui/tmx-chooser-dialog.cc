// -*- c-basic-offset: 2; c-indentation-style: ellemtel; -*-

//  Copyright (C) 2012

// This file is part of iAtal.

// iAtal is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// iAtal is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with iAtal.  If not, see <http://www.gnu.org/licenses/>.

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
