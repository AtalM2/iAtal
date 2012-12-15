// -*- c-basic-offset: 2; -*-
#ifndef IATAL_UI_MANAGER_H
#define IATAL_UI_MANAGER_H

#include <gtkmm.h>

class IAtalUIManager : public Gtk::UIManager
{

public:
  static Glib::RefPtr< IAtalUIManager > create();
  virtual ~IAtalUIManager();
  
  void setPathSensitivity(const Glib::ustring & path,
			  bool sensitivity);

protected:
  IAtalUIManager();

};

#endif // IATAL_UI_MANAGER_H
