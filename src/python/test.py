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
	global northDirection
	northDirection = direction(0,1)
	global southDirection
	southDirection = direction(0,-1)
	global westDirection
	westDirection = direction(-1,0)
	global eastDirection
	eastDirection = direction(0,1)
	#direction initiale
	eastDirection.activate()


	global undergroundSensor 
	undergroundSensor = sensor(map_,enums.Level.Underground, 1)
	global greenActuator 
	greenActuator = actuator(map_,enums.Level.Underground, 1, "type:vert")

#stratégie python
def strat():
	print("debut strat")
	ugSense = undergroundSensor.activate()
	print(ugSense)
	if ugSense=="type:marron" :
		greenActuator.activate()
		ugSense = undergroundSensor.activate()
		print(ugSense)
		if ugSense!="nothing" :
			map_.goForward()
	elif ugSense=="nothing" :
		print("change direction ! ")	
			
	print(ugSense)
	global ended
	ended = True

#sert à savoir si la strat est finie ou non
def isEnded():
	return ended;

