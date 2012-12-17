// -*- c-basic-offset: 2; -*-
#ifndef STATUS_HBOX_H
#define STATUS_HBOX_H

#include <gtkmm.h>

/**
 * Container that's used in iAtal to handle the status of the map and
 * strategy related information.
 */
class StatusHBox : public Gtk::HBox
{

 public:
  /**
   * Constructor.
   */
  StatusHBox();

  /**
   * Destructor.
   */
  virtual ~StatusHBox();
  
  /**
   * Display the correct image to represent the map status.
   */
  void setMapStatusOk(bool ok);

  /**
   * Display the correct image to represent the strategy status.
   */
  void setStrategyStatusOk(bool ok);
  
 private:

  /**
   * Image of the map status.
   */
  Gtk::Image mapImage_,
    
    /**
     * Image of the strategy status.
     */
    strategyImage_;

  /**
   * Label of the map status.
   */
  Gtk::Label mapLabel_,
    
    /**
     * Label of the strategy status.
     */
    strategyLabel_;
};

#endif // STATUS_HBOX_H
