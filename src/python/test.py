#!/usr/bin/env python
# -*- coding: utf-8 -*-

import elements
import enums
import os

from classes import *
from init_strat import *

#global
compteur = 0
#map_ = False
ended = False

#map loading
global map_ 
	map_ = loadMap()

#position and direction initialization
def robot_init():
	map_.setDirection(0,1)
	map_.setPosition(0,0)


#stratégie python
def strat():
	gSense = groundSensor()
	print(gSense)
	if gSense=="type:herbe" :
		oSense = objectSensor()
		print(oSense)
		if oSense!="":
			global ended
			ended = True
			print("End of strategy")
		walk()
	else:
		print("change direction ! ")
		turnLeft()




#sensors

	#one tile ahead	
def undergroundSensorOnSelf():
	return sensor(map_,enums.Level.Underground, 0).activate()

def groundSensorOnSelf():
	return sensor(map_,enums.Level.Ground, 0).activate()

def objectSensorOnSelf():
	return sensor(map_,enums.Level.Object, 0).activate()

def airSensorOnSelf(): 
	return sensor(map_,enums.Level.Air, 0).activate()

	#on self
def undergroundSensor():
	return sensor(map_,enums.Level.Underground, 1).activate()

def groundSensor():
	return sensor(map_,enums.Level.Ground, 1).activate()

def objectSensor():
	return sensor(map_,enums.Level.Object, 1).activate()

def airSensor(): 
	return sensor(map_,enums.Level.Air, 1).activate()




#actuators

	#underground
def greenActuator():
	return actuator(map_,enums.Level.Underground, 1, "type:vert").activate()
	
def	brownActuator():
	return actuator(map_,enums.Level.Underground, 1, "type:marron").activate()

def	whiteActuator():
	return actuator(map_,enums.Level.Underground, 1, "type:blanc").activate()

def	blueActuator():
	return actuator(map_,enums.Level.Underground, 1, "type:bleu").activate()

	#ground
def	herbeActuator():
	return actuator(map_,enums.Level.Ground, 1, "type:herbe").activate()

def	eauActuator():
	return actuator(map_,enums.Level.Ground, 1, "type:eau").activate()

	#object
def	fleurActuator():
	return actuator(map_,enums.Level.Object, 1, "type:fleur").activate()

def	champiActuator():
	return actuator(map_,enums.Level.Object, 1, "couleur:rouge").activate()


#sert à savoir si la strat est finie ou non
def isEnded():
	return ended;	
