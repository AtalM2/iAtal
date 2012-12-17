#!/usr/bin/env python
# -*- coding: utf-8 -*-

import elements
import enums
import os
import random

from classes import *

global compteur
compteur = 0
#map_ = False
ended = False


def init(aMap):
	global map_
	map_ = aMap


#position and direction initialization
global x_init
x_init = 2
global y_init
y_init = 1

def robot_init():
	map_.setDirection(0,1)
	map_.setPosition(x_init,y_init)
	base = "src/tmx/resources/"
	map_.setRobotImage(base +"donald_dos_gauche.png",
			   base + "donald_face_droite.png",
			   base + "donald_dos_droite.png",
			   base + "donald_face_gauche.png")
	print("Starting at ( " + str(x_init) + ", " + str(y_init) + " )")
	sensors_init()
	actuators_init()

def sensors_init():
	global undergroundSensor
	undergroundSensor = sensor(map_, enums.Level.Underground,1)
	global groundSensor
	groundSensor = sensor(map_,enums.Level.Ground,1)

	global objectSensor
	objectSensor = sensor(map_, enums.Level.Object,1)

	global compassSensor
	compassSensor = compass(map_)

def actuators_init():
	global destroyer
	destroyer = actuator(map_,enums.Level.Object, 1, "exploded:")
	global loveLatex
	loveLatex = actuator(map_,enums.Level.Object, 1, "lovelatex:")
	global loveTaocp
	loveTaocp = actuator(map_,enums.Level.Object, 1, "lovetaocp:")


#stratégie python
def strat():
	cs = compassSensor.activate()
	ugSense = undergroundSensor.activate()
	gSense = groundSensor.activate()
	#print(gSense)
	oSense = objectSensor.activate()
	print(oSense)
	print("Facing " + cs + " in front of : " + gSense)
	if ((oSense=="word") | (oSense=="windows") | (oSense=="libreoffice") | (oSense=="powerpoint")):
		print("I've found a WYSIWYG ! Destroy it ! ")
		destroyer.activate()
		global compteur
		compteur = compteur + 1
		if compteur == 8:
			global ended
			ended = True
			print("Strat end")
	elif oSense=="latex":
		loveLatex.activate()
	elif oSense=="taocp":
		loveTaocp.activate()

	if ((gSense!="mur") & (ugSense=="sol")):
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


#sert à savoir si la strat est finie ou non
def isEnded():
	return ended;


#shorthands

def walk():
	map_.goForward()

def turnLeft():
	map_.turnLeft()

def turnRight():
	map_.turnRight()
	




'''

#sensors

	#on self
def undergroundSensorOnSelf():
	return sensor(map_,enums.Level.Underground, 0).activate()

def groundSensorOnSelf():
	return sensor(map_,enums.Level.Ground, 0).activate()

def objectSensorOnSelf():
	return sensor(map_,enums.Level.Object, 0).activate()

def airSensorOnSelf(): 
	return sensor(map_,enums.Level.Air, 0).activate()

	#one tile ahead
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

#ground
	
#object
def destroyActuator():
	return actuator(map_,enums.Level.Object, 1, "exploded:").activate()
'''

	
