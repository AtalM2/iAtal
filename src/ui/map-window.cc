// -*- c-basic-offset: 2; -*-
#include "map-window.h"

#include <iostream>

#include <boost/lexical_cast.hpp>
#include <gtkmm/stock.h>

#include "controllers/map-controller.h"

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
  //Create actions for menus and toolbars:
  m_refActionGroup = Gtk::ActionGroup::create();

  m_refActionGroup->add(Gtk::Action::create("FileMenu", "File"));

  m_refActionGroup->add(
    Gtk::Action::create("FileOpenMap",
			Gtk::Stock::OPEN,
			"_Open a map",
			"Load a TMX map"),
    sigc::mem_fun(mc_, &MapController::loadMap));

  m_refActionGroup->add(
    Gtk::Action::create("FileOpenStrategy",
			Gtk::Stock::SELECT_ALL,
			"_Select a strategy",
			"Load a python strategy"),
    sigc::mem_fun(*this, &MapWindow::onMenuOpenStrategy));

  m_refActionGroup->add(
    Gtk::Action::create("FileQuit",
			Gtk::Stock::QUIT,
			"Quit",
			"Quit iAtal"),
    sigc::mem_fun(*this, &MapWindow::onMenuQuit));

  //Edit menu:
  m_refActionGroup->add(
    Gtk::Action::create("StrategyMenu", "Strategy"));

  m_refActionGroup->add(
    Gtk::Action::create("StrategyNextStep",
			Gtk::Stock::MEDIA_PLAY,
			"_Next step",
			"Execute the next step of the strategy"),
    sigc::mem_fun(sc_, &StrategyController::nextStep));

  m_refActionGroup->add(
    Gtk::Action::create("StrategyAutoStepsOn",
			Gtk::Stock::MEDIA_FORWARD,
			"Turn on _Auto mode",
			"Execute steps automatically"),
    sigc::mem_fun(sc_, &StrategyController::autoStepsOn));

  m_refActionGroup->add(
    Gtk::Action::create("StrategyAutoStepsOff",
			Gtk::Stock::MEDIA_PAUSE,
			"Turn _off Auto mode",
			"Go back to manual mode"),
    sigc::mem_fun(sc_, &StrategyController::autoStepsOff));

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
  
  Glib::RefPtr< Gtk::Action > ac =
    m_refUIManager->get_action("/ToolBar/StrategyAutoStepsOff");
  
  if(ac)
    ac->set_sensitive(false);
  
  vBox.pack_start(hBox);
  show_all_children();
}


MapWindow::~MapWindow()
{
}

void MapWindow::onMenuQuit()
{
  hide();
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

void MapWindow::onMenuOpenStrategy()
{
  Gtk::FileChooserDialog dialog("Please choose a strategy file to load",
				Gtk::FILE_CHOOSER_ACTION_OPEN);
  dialog.set_transient_for(*this);

  //Add response buttons the the dialog:
  dialog.add_button(Gtk::Stock::CANCEL,
		    Gtk::RESPONSE_CANCEL);
  dialog.add_button(Gtk::Stock::OPEN,
		    Gtk::RESPONSE_OK);

  //Add filters, so that only certain file types can be selected:
  Glib::RefPtr<Gtk::FileFilter> filter_py =
    Gtk::FileFilter::create();
  filter_py->set_name("Python files");
  filter_py->add_pattern("*.py");
  dialog.add_filter(filter_py);
  
  Glib::RefPtr<Gtk::FileFilter> filter_any =
    Gtk::FileFilter::create();
  filter_any->set_name("Any files");
  filter_any->add_pattern("*");
  dialog.add_filter(filter_any);

  //Show the dialog and wait for a user response:
  int result = dialog.run();

  //Handle the response:
  if(result == Gtk::RESPONSE_OK)
    {
      std::cout << "Open clicked." << std::endl;
      
      //Notice that this is a std::string, not a Glib::ustring.
      std::string filename = dialog.get_filename();
      std::cout << "File selected: " <<  filename << std::endl;
    }
}
