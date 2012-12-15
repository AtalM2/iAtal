// -*- c-basic-offset: 2; -*-

#ifndef MAPWINDOW_H
#define MAPWINDOW_H

#include <iostream>
#include <memory>
#include <string>

#include <gtkmm.h>

#include "maparea.h"
#include "controllers/map-controller.h"
#include "controllers/strategy-controller.h"

class MapWindow : public Gtk::Window
{

public:
  MapWindow();
  virtual ~MapWindow();
  void displayWarning(const Glib::ustring & title,
		      const Glib::ustring & text);
  Gtk::VBox vBox;
  Gtk::Image mapImage, strategyImage;
  
protected:
  Gtk::HBox hBox;
  Gtk::Label mapStatus,
    strategyStatus;
  //Signal handlers:
  void onMenuQuit();
  void on_menu_others();
  void onMenuOpenMap();
  void onMenuOpenStrategy();

  //Child widgets:

  Glib::RefPtr<Gtk::UIManager> m_refUIManager;
  Glib::RefPtr<Gtk::ActionGroup> m_refActionGroup;
  Glib::RefPtr<Gtk::RadioAction> m_refChoiceOne, m_refChoiceTwo;

 private:
  MapController & mc_;
  StrategyController & sc_;
};

#endif // MAPWINDOW_H
