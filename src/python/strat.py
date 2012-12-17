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
			   base + "donald_face_gauche.png",
			   base + "donald_face_droite.png",
			   base + "donald_dos_droite.png")
	print("Starting at ( " + str(x_init) + ", " + str(y_init) + " )")


#stratégie python
def strat():
	cs = compassSensor(map_)
	
	gSense = groundSensor()
	#print(gSense)
	ugSense = undergroundSensor()
	#print(ugSense)
	oSense = objectSensor()
	print(oSense)
	print("Facing " + cs + " in front of : " + gSense)
	if oSense=="windows":
		print("I've found a Windows ! Destroy it ! ")
		destroyActuator()
		global ended
		ended = True
		print("Strat end")

	if gSense!="mur":
		print("walking...")
		walk(map_)
	else:
		turningLeft = random.choice([True, False])
		if turningLeft:
			print("turning left...")
			turnLeft(map_)
		else:
			print("turning right...")
			turnRight(map_)




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

#ground
	
#object
def destroyActuator():
	return actuator(map_,enums.Level.Object, 1, "exploded:").activate()


#sert à savoir si la strat est finie ou non
def isEnded():
	return ended;	
