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

#include "ui/status-hbox.h"

using namespace iatal;

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
