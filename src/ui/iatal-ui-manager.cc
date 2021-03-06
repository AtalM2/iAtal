// -*- c-basic-offset: 2; c-indentation-style: ellemtel; -*-

//  Copyright (C) 2012

// This file is part of iAtal.

// iAtal is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// iAtal is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with iAtal.  If not, see <http://www.gnu.org/licenses/>.

#include "controllers/map-controller.h"

#include "iatal-ui-manager.h"

#include "controllers/app-controller.h"
#include "controllers/strategy-controller.h"
#include "exceptions/model/bad-parameters-exception.h"

using namespace iatal;

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
  AppController & ac = AppController::getInstance();
  
  // Create actions for menus and toolbars:
  Glib::RefPtr< Gtk::ActionGroup > actionGroup =
    Gtk::ActionGroup::create();

  // File menu:
  actionGroup->add(Gtk::Action::create("FileMenu", "File"));

  actionGroup->add(
    Gtk::Action::create("FileOpenMap",
                        Gtk::Stock::OPEN,
                        "_Open a map",
                        "Load a TMX map"),
    sigc::mem_fun(mc, &MapController::loadMap));

  actionGroup->add(
    Gtk::Action::create("FileOpenStrategy",
                        Gtk::Stock::SELECT_ALL,
                        "_Select a strategy",
                        "Load a python strategy"),
    sigc::mem_fun(sc, &StrategyController::loadStrategy));

  actionGroup->add(
    Gtk::Action::create("FileQuit",
                        Gtk::Stock::QUIT,
                        "Quit",
                        "Quit iAtal"),
    sigc::mem_fun(ac, &AppController::quit));

  // Strategy menu:
  actionGroup->add(
    Gtk::Action::create("StrategyMenu", "Strategy"));
  actionGroup->add(
    Gtk::Action::create("StrategyRewind",
                        Gtk::Stock::MEDIA_PREVIOUS,
                        "_Rewind",
                        "Reload the strategy"),
    sigc::mem_fun(sc, &StrategyController::rewind));
  
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

  //Help menu:
  actionGroup->add( Gtk::Action::create("HelpMenu", "Help") );
  
  actionGroup->add(
    Gtk::Action::create("HelpAbout",
                        Gtk::Stock::HELP,
                        "About iAtal",
                        "Misc info about iAtal"),
    sigc::mem_fun(ac, &AppController::help) );

  insert_action_group(actionGroup);

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
    "   <menuitem action='StrategyRewind'/>"
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
    "  <toolitem action='StrategyRewind'/>"
    "  <toolitem action='StrategyNextStep'/>"
    "  <toolitem action='StrategyAutoStepsOn'/>"
    "  <toolitem action='StrategyAutoStepsOff'/>"
    "  <separator/>"
    "  <toolitem action='FileQuit'/>"
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

  setPathSensitivity("/ToolBar/FileOpenStrategy", false);
  
  setPathSensitivity("/ToolBar/StrategyRewind", false);
  setPathSensitivity("/ToolBar/StrategyNextStep", false);
  setPathSensitivity("/ToolBar/StrategyAutoStepsOn", false);
  setPathSensitivity("/ToolBar/StrategyAutoStepsOff", false);
  
}

Gtk::Widget &
IAtalUIManager::getMenuBar()
{
  return *get_widget("/MenuBar");
}

Gtk::Widget &
IAtalUIManager::getToolBar()
{
  return *get_widget("/ToolBar");
}

void
IAtalUIManager::setPathSensitivity(const Glib::ustring & path,
                                   bool sensitivity)
{
  Glib::RefPtr< Gtk::Action > ac = get_action(path);
  
  if(ac)
    ac->set_sensitive(sensitivity);
}
