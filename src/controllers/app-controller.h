// -*- c-basic-offset: 2; -*-

#ifndef APP_CONTROLLER_H
#define APP_CONTROLLER_H

#include <memory>

#include <gtkmm.h>

class MapWindow;

class AppController
{
 public:
  static AppController & getInstance()
  {
    static AppController instance;
    return instance;
  }
  
  void setWindow(const std::shared_ptr< MapWindow > & window);

  void displayWarning(const Glib::ustring & title,
		      const Glib::ustring & text);
  
  void displayError(const Glib::ustring & title,
		    const Glib::ustring & text);
  
  static void displayAbout();
  
  void quit();
  
 private:
  std::shared_ptr< MapWindow > window_;
  
  AppController();
  
  // Don't Implement, singleton
  AppController(const AppController &);
  
  // Don't implement, singleton
  void operator=(const AppController &);
};
#endif // APP_CONTROLLER_H
