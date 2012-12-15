// -*- c-basic-offset: 2; -*-
#include "controllers/map-controller.h"

#include "iatal-ui-manager.h"

#include "controllers/strategy-controller.h"

Glib::RefPtr< IAtalUIManager >
IAtalUIManager::create()
{
  return Glib::RefPtr< IAtalUIManager >(new IAtalUIManager);
}

IAtalUIManager::~IAtalUIManager()
{
  
}

IAtalUIManager::IAtalUIManager()
{
  MapController & mc = MapController::getInstance();
  StrategyController & sc = StrategyController::getInstance();
  
  //Create actions for menus and toolbars:
  Glib::RefPtr< Gtk::ActionGroup > actionGroup =
    Gtk::ActionGroup::create();

  actionGroup->add(Gtk::Action::create("FileMenu", "File"));

  actionGroup->add(
    Gtk::Action::create("FileOpenMap",
			Gtk::Stock::OPEN,
			"_Open a map",
			"Load a TMX map"),
    sigc::mem_fun(mc, &MapController::loadMap));

  // m_refActionGroup->add(
  //   Gtk::Action::create("FileOpenStrategy",
  // 			Gtk::Stock::SELECT_ALL,
  // 			"_Select a strategy",
  // 			"Load a python strategy"),
  //   sigc::mem_fun(*this, &MapWindow::onMenuOpenStrategy));

  // m_refActionGroup->add(
  //   Gtk::Action::create("FileQuit",
  // 			Gtk::Stock::QUIT,
  // 			"Quit",
  // 			"Quit iAtal"),
  //   sigc::mem_fun(*this, &MapWindow::onMenuQuit));

  //Edit menu:
  actionGroup->add(
    Gtk::Action::create("StrategyMenu", "Strategy"));

  actionGroup->add(
    Gtk::Action::create("StrategyNextStep",
			Gtk::Stock::MEDIA_PLAY,
			"_Next step",
			"Execute the next step of the strategy"),
    sigc::mem_fun(sc, &StrategyController::nextStep));

  actionGroup->add(
    Gtk::Action::create("StrategyAutoStepsOn",
			Gtk::Stock::MEDIA_FORWARD,
			"Turn on _Auto mode",
			"Execute steps automatically"),
    sigc::mem_fun(sc, &StrategyController::autoStepsOn));

  actionGroup->add(
    Gtk::Action::create("StrategyAutoStepsOff",
			Gtk::Stock::MEDIA_PAUSE,
			"Turn _off Auto mode",
			"Go back to manual mode"),
    sigc::mem_fun(sc, &StrategyController::autoStepsOff));

  // //Help menu:
  // m_refActionGroup->add( Gtk::Action::create("HelpMenu", "Help") );
  // m_refActionGroup->add( Gtk::Action::create("HelpAbout", Gtk::Stock::HELP),
  // 			 sigc::mem_fun(*this, &MapWindow::on_menu_others) );

  insert_action_group(actionGroup);

  //Layout the actions in a menubar and toolbar:
  Glib::ustring ui_info =
    "<ui>"
    " <menubar name='MenuBar'>"
    "  <menu action='FileMenu'>"
    "   <menuitem action='FileOpenMap'/>"
    // "   <menuitem action='FileOpenStrategy'/>"
    "   <separator/>"
    // "   <menuitem action='FileQuit'/>"
    "  </menu>"
    "  <menu action='StrategyMenu'>"
    "   <menuitem action='StrategyNextStep'/>"
    "   <menuitem action='StrategyAutoStepsOn'/>"
    "   <menuitem action='StrategyAutoStepsOff'/>"
    "  </menu>"
    // "  <menu action='HelpMenu'>"
    // "   <menuitem action='HelpAbout'/>"
    // "  </menu>"
    " </menubar>"
    " <toolbar  name='ToolBar'>"
    "  <toolitem action='FileOpenMap'/>"
    // "  <toolitem action='FileOpenStrategy'/>"
    "  <separator/>"
    "  <toolitem action='StrategyNextStep'/>"
    "  <toolitem action='StrategyAutoStepsOn'/>"
    "  <toolitem action='StrategyAutoStepsOff'/>"
    "  <separator/>"
    // "  <toolitem action='FileQuit'/>"
    " </toolbar>"
    "</ui>";

  try
    {
      add_ui_from_string(ui_info);
    }
  catch(const Glib::Error& ex)
    {
      std::cerr << "building menus failed: " <<  ex.what();
    }

}
