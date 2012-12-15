#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
sys.path.append(".libs")
#import elements
import enums

#globals
ended = False
compteur = 0
map_ = False

def init(aMap):
	global map_ 
	map_ = aMap

def robot_init():
	global undergroundSensor 
	undergroundSensor = sensor(enums.Level.Underground, 1)
	global bibiActuator 
	bibiActuator = actuator(enums.Level.Underground, 1, "bibi")

#stratégie python
def strat():
	print(undergroundSensor.activate())
	bibiActuator.activate()
	print(undergroundSensor.activate())
	global ended
	ended = True

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
	def __init__(self, level_, range_,newContent_):
		self.map_ = map_
		self.level_ = level_
		self.range_ = range_
		self.newContent_ = newContent_
	
	def activate(self):
		self.map_.setItem(self.level_, self.range_, self.newContent_)
