// -*- c-basic-offset: 2; -*-
#ifndef MAP_WINDOW_H
#define MAP_WINDOW_H

#include "map-area.h"

#include <gtkmm.h>

#include "ui/iatal-ui-manager.h"
#include "ui/status-hbox.h"

/**
 * Main window of the iAtal application.
 */
class MapWindow : public Gtk::Window
{

public:
  /**
   * Constructor, sets up the different part of iAtal UI.
   */
  MapWindow();
  
  /**
   * Destructor.
   */
  virtual ~MapWindow();

  /**
   * Sets the status, menu and toolbar items correctly to indicate the
   * availability of the map.
   * 
   * \param ok The availability of the map.
   */
  void setMapStatusOk(bool ok);

  /**
   * Sets the status, menu and toolbar items correctly to indicate the
   * availability of the strategy.
   * 
   * \param ok The availability of the strategy.
   */
  void setStrategyStatusOk(bool ok);
  
  /**
   * Swaps the map used for the UI.
   * 
   * \param map The new map to use.
   */
  void setMap(const std::shared_ptr< iatal::Map > & map);
  
  /**
   * Sets whether or not a certain item in the menu and toolbar is
   * sensitive.
   * 
   * \param path The path to consider in the menu hierarchy.
   * \param sensitivity Whether to activate or deactivate path.
   */
  void setPathSensitivity(const Glib::ustring & path,
			  bool sensitivity);
  
 private:

  /**
   * Flag indicating if a map is currently loaded.
   */
  bool mapLoaded_;

  /**
   * Container used to store widgets in the main window.
   */
  Gtk::VBox vBox_;

  /**
   * Container used to store status related information.
   */
  StatusHBox hBox_;

  /**
   * Menus and toolbar manager.
   */
  Glib::RefPtr< IAtalUIManager > uiManager_;

  /**
   * Widget in charge of displaying the map.
   */
  MapArea area_;
};

#endif // MAP_WINDOW_H
