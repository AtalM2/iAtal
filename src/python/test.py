#!/usr/bin/env python
# -*- coding: utf-8 -*-

import elements
import enums
import os

from classes import *

#global
compteur = 0
map_ = False
ended = False


def walk():
	map_.goForward()

def turnLeft():
	map_.turnLeft()

def turnRight():
	map_.turnRight()


def init(aMap):
	global map_ 
	map_ = aMap

def robot_init():
	map_.setDirection(0,1)
	map_.setPosition(0,0)

	#sensors
	global undergroundSensor 
	undergroundSensor = sensor(map_,enums.Level.Underground, 1)
	global groundSensor 
	groundSensor = sensor(map_,enums.Level.Ground, 1)
	global objectSensor 
	objectSensor = sensor(map_,enums.Level.Object, 1)
	global airSensor 
	airSensor = sensor(map_,enums.Level.Air, 1)

	#actuators

	#underground
	global greenActuator 
	greenActuator = actuator(map_,enums.Level.Underground, 1, "type:vert")
	global brownActuator 
	brownActuator = actuator(map_,enums.Level.Underground, 1, "type:marron")
	global whiteActuator 
	whiteActuator = actuator(map_,enums.Level.Underground, 1, "type:blanc")
	global blueActuator 
	blueActuator = actuator(map_,enums.Level.Underground, 1, "type:bleu")

	#ground
	global herbeActuator 
	herbeActuator = actuator(map_,enums.Level.Ground, 1, "type:herbe")
	global eauActuator 
	eauActuator = actuator(map_,enums.Level.Ground, 1, "type:eau")

	#object
	global fleurActuator 
	fleurActuator = actuator(map_,enums.Level.Object, 1, "type:fleur")
	global champiActuator 
	champiActuator = actuator(map_,enums.Level.Object, 1, "type:champi")
	

#stratégie python
def strat():
	gSense = groundSensor.activate()
	print(gSense)
	if gSense=="type:herbe" :
		oSense = objectSensor.activate()
		print(oSense)
		if oSense!="":
			global ended
			ended = True
			print("End of strategy")
		walk()
	else:
		print("change direction ! ")
		turnLeft()


#sert à savoir si la strat est finie ou non
def isEnded():
	return ended;

