#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
sys.path.append(".libs")
import elements
import enums

#globals
ended = False
compteur = 0
map_ = False

def init(aMap):
	global map_ 
	map_ = aMap

#stratégie python
def strat():
	undergroundSensor = sensor(enums.Level.Underground, 1)
	print(mysens.activate())

#sert à savoir si la strat est finie ou non
def isEnded():
	return ended;

#Defines a sensor.
class sensor:
	def __init__(self,level_, range_):
		self.map_ = map_
		self.level_ = level_
		self.range_ = range_
	def activate(self):
		return map_.getItem(self.level_ , self.range_)

#defines an actuator
class actuator:
	def __init__(self, level_, range_,newcontent_):
		self.map_ = map_
		self.level_ = level_
		self.range_ = range_
		self.newcontent_ = newcontent_
	
	def activate(self, aMap):
		pass
