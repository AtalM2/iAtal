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
	global undergroundSensor 
	undergroundSensor = sensor(map_,enums.Level.Underground, 1)
	global greenActuator 
	greenActuator = actuator(map_,enums.Level.Underground, 1, "type:vert")

#stratégie python
def strat():
	print(undergroundSensor.activate())
	greenActuator.activate()
	print(undergroundSensor.activate())
	global ended
	ended = True

#sert à savoir si la strat est finie ou non
def isEnded():
	return ended;

