// -*- c-basic-offset: 2; -*-
#ifndef IATAL_UI_MANAGER_H
#define IATAL_UI_MANAGER_H

#include <gtkmm.h>

/**
 * Menu and toolbar handling class for iAtal.
 */
class IAtalUIManager : public Gtk::UIManager
{

 public:
  /**
   * Glib style create, returns a RefPtr containing our newly made
   * objetc. It's the only method that should call the constructor to
   * ensure the efficiency of the RefPtr.
   */
  static Glib::RefPtr< IAtalUIManager > create();
  
  /**
   * Destructor.
   */
  virtual ~IAtalUIManager();
  
  /**
   * Returns the widget that corresponds to the MenuBar. Convenient
   * method since it's created from a string and isn't accessible in a
   * typesafe manner.
   */
  Gtk::Widget & getMenuBar();
  
  /**
   * Returns the widget that corresponds to the ToolBar. Convenient
   * method since it's created from a string and isn't accessible in a
   * typesafe manner.
   */
  Gtk::Widget & getToolBar();
  
  /**
   * Sets a certain item's sensitivity. Allows for quick locking of
   * the menu and toolbar items.
   * 
   * \param path The path in the menu hierarchy of the item to
   * process.
   * 
   * \param sensitivity The action to perform: enable or disable.
   */
  void setPathSensitivity(const Glib::ustring & path,
			  bool sensitivity);

protected:
  /**
   * Should never be called by another method than IAtalUIManager::create().
   */
  IAtalUIManager();

};

#endif // IATAL_UI_MANAGER_H
