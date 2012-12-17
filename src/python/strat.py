#!/usr/bin/env python
# -*- coding: utf-8 -*-

import elements
import enums
import os
import random

from classes import *
from init_strat import *

#global
compteur = 0
#map_ = False
ended = False

#map loading
#global map_ 
#map_ = loadMap()

def init(aMap):
	global map_ 
	map_ = aMap


def walk():
	map_.goForward()

def turnLeft():
	map_.turnLeft()

def turnRight():
	map_.turnRight()



#position and direction initialization
def robot_init():
	map_.setDirection(0,1)
	map_.setPosition(5,10)


#stratégie python
def strat():
	gSense = groundSensor()
	#print(gSense)
	ugSense = undergroundSensor()
	#print(ugSense)
	oSense = objectSensor()
	#print(oSense)
	if ugSense=="sol:":
		if oSense!="":
			print("I've found a " + oSense + " !")
			global ended
			ended = True
			print("Strat end")
		print("walking...")
		walk()
	else:
		turningLeft = random.choice([True, False])	
		if turningLeft:
			print("turning left...")
			turnLeft()
		else:
			print("turning right...")
			turnRight()




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
