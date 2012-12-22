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
   * 
   * \param ok The availability of the map.x
   */
  void setMapStatusOk(bool ok);

  /**
   * Display the correct image to represent the strategy status.
   * 
   * \param ok The availability of the strategy.
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
