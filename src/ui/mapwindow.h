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
  MapWindow(const std::shared_ptr< Map > & map,
	    StrategyController & sc);
  virtual ~MapWindow();
  void displayWarning(const Glib::ustring & title,
		      const Glib::ustring & text);
  
protected:
  StrategyController sc;
  Gtk::HBox hBox;
  Gtk::VBox vBox;
  Gtk::Label mapStatus,
    strategyStatus;
  Gtk::Image mapImage, strategyImage;
  MapArea area;
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
};

#endif // MAPWINDOW_H
