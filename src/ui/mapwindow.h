// -*- c-basic-offset: 2; -*-

#ifndef MAPWINDOW_H
#define MAPWINDOW_H

#include <iostream>
#include <memory>
#include <string>

#include <gtkmm.h>

#include "maparea.h"
#include "controllers/strategy-controller.h"

class MapWindow : public Gtk::Window
{

public:
  MapWindow(const std::shared_ptr< Map > & map,
	    StrategyController & sc);
  virtual ~MapWindow();
  
protected:
  StrategyController sc;
  Gtk::HBox hBox;
  Gtk::VBox vBox;
  Gtk::Label mapStatus,
    strategyStatus;
  Gtk::Image mapImage, strategyImage;
  MapArea area;
  //Signal handlers:
  void on_menu_file_new_generic();
  void on_menu_file_quit();
  void on_menu_others();

  void on_menu_choices_one();
  void on_menu_choices_two();

  //Child widgets:

  Glib::RefPtr<Gtk::UIManager> m_refUIManager;
  Glib::RefPtr<Gtk::ActionGroup> m_refActionGroup;
  Glib::RefPtr<Gtk::RadioAction> m_refChoiceOne, m_refChoiceTwo;
};

#endif // MAPWINDOW_H
