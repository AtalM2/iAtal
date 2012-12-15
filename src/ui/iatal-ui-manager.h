// -*- c-basic-offset: 2; -*-
#ifndef IATAL_UI_MANAGER_H
#define IATAL_UI_MANAGER_H

#include <gtkmm.h>

class IAtalUIManager : public Gtk::UIManager
{

public:
  static Glib::RefPtr< IAtalUIManager > create();
  virtual ~IAtalUIManager();

protected:
  IAtalUIManager();

};

#endif // IATAL_UI_MANAGER_H
