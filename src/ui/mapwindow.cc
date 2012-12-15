// -*- c-basic-offset: 2; -*-

#include "mapwindow.h"
#include <boost/lexical_cast.hpp>
#include <gtkmm/stock.h>
#include <iostream>

MapWindow::MapWindow(const std::shared_ptr< Map > & map,
		     StrategyController & sc)
  : sc(sc),
    mapStatus("Map loaded: "),
    strategyStatus("Strategy loaded: "),
    mapImage(Gtk::Stock::YES, Gtk::ICON_SIZE_MENU),
    strategyImage(Gtk::Stock::NO, Gtk::ICON_SIZE_MENU),
    area(map)
{
  set_title("iAtal");
  set_icon_from_file("src/ui/img/icon.png");
  mapStatus.set_margin_left(5);
  mapImage.set_margin_right(5);
  strategyImage.set_margin_right(5);
  area.set_margin_left(5);
  area.set_margin_right(5);
  area.set_margin_bottom(5);
  area.set_margin_top(5);
  
  // Top hbox handling
  hBox.pack_start(mapStatus);
  hBox.pack_start(mapImage);
  hBox.pack_start(strategyStatus);
  hBox.pack_start(strategyImage);

  add(vBox); // put a MenuBar at the top of the box and other stuff below it.
  //Create actions for menus and toolbars:
  m_refActionGroup = Gtk::ActionGroup::create();

  m_refActionGroup->add(Gtk::Action::create("FileMenu", "File"));

  m_refActionGroup->add(
    Gtk::Action::create("FileOpenMap",
			Gtk::Stock::OPEN,
			"_Open a map",
			"Load a TMX map"),
    sigc::mem_fun(*this, &MapWindow::on_menu_others));

  m_refActionGroup->add(
    Gtk::Action::create("FileOpenStrategy",
			Gtk::Stock::SELECT_ALL,
			"_Select a strategy",
			"Load a python strategy"),
    sigc::mem_fun(*this, &MapWindow::on_menu_others));

  m_refActionGroup->add(
    Gtk::Action::create("FileQuit",
			Gtk::Stock::QUIT,
			"Quit",
			"Quit iAtal"),
    sigc::mem_fun(*this, &MapWindow::on_menu_file_quit));

  //Edit menu:
  m_refActionGroup->add(
    Gtk::Action::create("StrategyMenu", "Strategy"));

  m_refActionGroup->add(
    Gtk::Action::create("StrategyNextStep",
			Gtk::Stock::MEDIA_PLAY,
			"_Next step",
			"Execute the next step of the strategy"),
    sigc::mem_fun(sc, &StrategyController::nextStep));

  m_refActionGroup->add(
    Gtk::Action::create("StrategyAutoStepsOn",
			Gtk::Stock::MEDIA_FORWARD,
			"Turn on _Auto mode",
			"Execute steps automatically"),
    sigc::mem_fun(sc, &StrategyController::autoStepsOn));

  m_refActionGroup->add(
    Gtk::Action::create("StrategyAutoStepsOff",
			Gtk::Stock::MEDIA_PAUSE,
			"Turn _off Auto mode",
			"Go back to manual mode"),
    sigc::mem_fun(sc, &StrategyController::autoStepsOff));

  //Help menu:
  m_refActionGroup->add( Gtk::Action::create("HelpMenu", "Help") );
  m_refActionGroup->add( Gtk::Action::create("HelpAbout", Gtk::Stock::HELP),
			 sigc::mem_fun(*this, &MapWindow::on_menu_others) );

  m_refUIManager = Gtk::UIManager::create();
  m_refUIManager->insert_action_group(m_refActionGroup);

  add_accel_group(m_refUIManager->get_accel_group());

  //Layout the actions in a menubar and toolbar:
  Glib::ustring ui_info =
    "<ui>"
    " <menubar name='MenuBar'>"
    "  <menu action='FileMenu'>"
    "   <menuitem action='FileOpenMap'/>"
    "   <menuitem action='FileOpenStrategy'/>"
    "   <separator/>"
    "   <menuitem action='FileQuit'/>"
    "  </menu>"
    "  <menu action='StrategyMenu'>"
    "   <menuitem action='StrategyNextStep'/>"
    "   <menuitem action='StrategyAutoStepsOn'/>"
    "   <menuitem action='StrategyAutoStepsOff'/>"
    "  </menu>"
    "  <menu action='HelpMenu'>"
    "   <menuitem action='HelpAbout'/>"
    "  </menu>"
    " </menubar>"
    " <toolbar  name='ToolBar'>"
    "  <toolitem action='FileOpenMap'/>"
    "  <toolitem action='FileOpenStrategy'/>"
    "  <separator/>"
    "  <toolitem action='StrategyNextStep'/>"
    "  <toolitem action='StrategyAutoStepsOn'/>"
    "  <toolitem action='StrategyAutoStepsOff'/>"
    "  <separator/>"
    "  <toolitem action='FileQuit'/>"
    " </toolbar>"
    "</ui>";

  try
    {
      m_refUIManager->add_ui_from_string(ui_info);
    }
  catch(const Glib::Error& ex)
    {
      std::cerr << "building menus failed: " <<  ex.what();
    }

  //Get the menubar and toolbar widgets, and add them to a container widget:
  Gtk::Widget* pMenubar = m_refUIManager->get_widget("/MenuBar");
  if(pMenubar)
    vBox.pack_start(*pMenubar, Gtk::PACK_SHRINK);

  Gtk::Widget* pToolbar = m_refUIManager->get_widget("/ToolBar") ;
  if(pToolbar)
    vBox.pack_start(*pToolbar, Gtk::PACK_SHRINK);

  vBox.pack_start(hBox);
  vBox.pack_start(area);
  show_all_children();
}


MapWindow::~MapWindow()
{
}

void MapWindow::on_menu_file_quit()
{
  hide();
}

void MapWindow::on_menu_others()
{
  std::cout << "A menu item was selected." << std::endl;
}
