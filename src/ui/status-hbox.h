// -*- c-basic-offset: 2; -*-
#ifndef STATUS_HBOX_H
#define STATUS_HBOX_H

#include <gtkmm.h>

class StatusHBox : public Gtk::HBox
{

 public:
  StatusHBox();
  virtual ~StatusHBox();
  
  void setMapStatusOk(bool ok);
  void setStrategyStatusOk(bool ok);
  
 private:
  Gtk::Image mapImage_, strategyImage_;
  Gtk::Label mapLabel_, strategyLabel_;
};

#endif // STATUS_HBOX_H
