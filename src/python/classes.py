#!/usr/bin/env python
# -*- coding: utf-8 -*-

#  Copyright (C) 2012
#
# This file is part of iAtal.
#
# iAtal is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# iAtal is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with iAtal.  If not, see <http://www.gnu.org/licenses/>.

#Defines a sensor.
class sensor:
	def __init__(self,map_, level_, range_):
		self.map_ = map_
		self.level_ = level_
		self.range_ = range_
	#gets the item in range on the map
	def activate(self):
		return self.map_.getItem(self.level_ , self.range_)

class compass:
	def __init__(self,map_):
		self.map_ = map_
	def activate(self):
		return self.map_.compass()

#defines an actuator
class actuator:
	def __init__(self,map_, level_, range_,newContent_):
		self.map_ = map_
		self.level_ = level_
		self.range_ = range_
		self.newContent_ = newContent_
	#Set the new item on the map
	def activate(self):
		self.map_.setItem(self.level_, self.range_, self.newContent_)
