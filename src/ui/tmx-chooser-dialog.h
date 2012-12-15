// -*- c-basic-offset: 2; -*-
#ifndef TMX_CHOOSER_DIALOG_H
#define TMX_CHOOSER_DIALOG_H

#include <gtkmm.h>

class TmxChooserDialog : public Gtk::FileChooserDialog
{

public:
  TmxChooserDialog();
  virtual ~TmxChooserDialog();
};

#endif // TMX_CHOOSER_DIALOG_H
