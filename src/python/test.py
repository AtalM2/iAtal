#!/usr/bin/env python
# -*- coding: utf-8 -*-

import elements
import enums
import os

from classes import *

#global
compteur = 0

def init(aMap):
	global map_ 
	map_ = aMap

def robot_init():
	map_.setDirection(0,1)

	#sensors
	global undergroundSensor 
	undergroundSensor = sensor(map_,enums.Level.Underground, 1)
	global groundSensor 
	groundSensor = sensor(map_,enums.Level.Ground, 1)

	#actuators
	global greenActuator 
	greenActuator = actuator(map_,enums.Level.Underground, 1, "type:vert")

#stratégie python
def strat():
	gSense = groundSensor.activate()
	print(gSense)
	if gSense=="type:herbe" :
		map_.goForward()
	if gSense=="nothing" :
#		greenActuator.activate()
#		ugSense = undergroundSensor.activate()
#		print(ugSense)
#		if ugSense!="nothing" :
#			
#	elif ugSense=="nothing" :
		print("change direction ! ")	
			
#	print(ugSense)
	global ended
	ended = True

#sert à savoir si la strat est finie ou non
def isEnded():
	return ended;

