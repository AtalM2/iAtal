// -*- c-basic-offset: 2; -*-
#include "map-window.h"

#include <iostream>

#include <boost/lexical_cast.hpp>
#include <gtkmm/stock.h>

#include "controllers/map-controller.h"
#include "ui/python-chooser-dialog.h"
#include "ui/iatal-ui-manager.h"

MapWindow::MapWindow()
  : mapImage(Gtk::Stock::NO, Gtk::ICON_SIZE_MENU),
    strategyImage(Gtk::Stock::NO, Gtk::ICON_SIZE_MENU),
    mapStatus("Map loaded: "),
    strategyStatus("Strategy loaded: "),
    mc_(MapController::getInstance()),
    sc_(StrategyController::getInstance())
{
  set_title("iAtal");
  set_icon_from_file("src/ui/img/icon.png");
  mapStatus.set_margin_left(5);
  mapImage.set_margin_right(5);
  strategyImage.set_margin_right(5);
  
  // Top hbox handling
  hBox.pack_start(mapStatus);
  hBox.pack_start(mapImage);
  hBox.pack_start(strategyStatus);
  hBox.pack_start(strategyImage);

  add(vBox); // put a MenuBar at the top of the box and other stuff below it.

  Glib::RefPtr< IAtalUIManager > uiManager =
    IAtalUIManager::create();
  
  add_accel_group(uiManager->get_accel_group());
  
  //Get the menubar and toolbar widgets, and add them to a container widget:
  Gtk::Widget* pMenubar = uiManager->get_widget("/MenuBar");
  if(pMenubar)
    vBox.pack_start(*pMenubar, Gtk::PACK_SHRINK);

  Gtk::Widget* pToolbar = uiManager->get_widget("/ToolBar") ;
  if(pToolbar)
    vBox.pack_start(*pToolbar, Gtk::PACK_SHRINK);
  
  Glib::RefPtr< Gtk::Action > ac =
    uiManager->get_action("/ToolBar/StrategyAutoStepsOff");
  
  if(ac)
    ac->set_sensitive(false);
  
  vBox.pack_start(hBox);
  show_all_children();
}


MapWindow::~MapWindow()
{
}

void MapWindow::on_menu_others()
{
  std::cout << "A menu item was selected." << std::endl;
}

void MapWindow::displayWarning(const Glib::ustring & title,
			       const Glib::ustring & text)
{
  Gtk::MessageDialog warning(*this,
			     title,
			     false,
			     Gtk::MESSAGE_WARNING,
			     Gtk::BUTTONS_CLOSE);
  warning.set_secondary_text(text);
  warning.run();
}
