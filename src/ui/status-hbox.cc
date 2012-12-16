// -*- c-basic-offset: 2; -*-
#include "ui/status-hbox.h"

StatusHBox::StatusHBox()
  : mapImage_(Gtk::Stock::NO, Gtk::ICON_SIZE_MENU),
    strategyImage_(Gtk::Stock::NO, Gtk::ICON_SIZE_MENU),
    mapLabel_("Map loaded:"),
    strategyLabel_("Strategy loaded:")
{
  set_margin_left(5);
  set_margin_right(5);
  set_margin_top(5);
  set_margin_bottom(5);
  set_spacing(5);
  set_valign(Gtk::Align::ALIGN_START);
  set_halign(Gtk::Align::ALIGN_START);
  
  pack_start(mapLabel_);
  pack_start(mapImage_);
  pack_start(strategyLabel_);
  pack_start(strategyImage_);
}

StatusHBox::~StatusHBox()
{
  
}

void
StatusHBox::setStrategyStatusOk(bool ok)
{
  if(ok)
    strategyImage_.set(Gtk::Stock::YES, Gtk::ICON_SIZE_MENU);
  else
    strategyImage_.set(Gtk::Stock::NO, Gtk::ICON_SIZE_MENU);      
}

void
StatusHBox::setMapStatusOk(bool ok)
{
  if(ok)
    mapImage_.set(Gtk::Stock::YES, Gtk::ICON_SIZE_MENU);
  else
    mapImage_.set(Gtk::Stock::NO, Gtk::ICON_SIZE_MENU);    
}
