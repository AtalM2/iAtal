// -*- c-basic-offset: 2; -*-
#ifndef TMX_CHOOSER_DIALOG_H
#define TMX_CHOOSER_DIALOG_H

#include <gtkmm.h>

/**
 * File chooser dialog tuned for tmx maps.
 */
class TmxChooserDialog : public Gtk::FileChooserDialog
{

public:
  /**
   * Constructor.
   */
  TmxChooserDialog();

  /**
   * Destructor.
   */
  virtual ~TmxChooserDialog();
};

#endif // TMX_CHOOSER_DIALOG_H
