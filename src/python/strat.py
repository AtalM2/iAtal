#!/usr/bin/env python
# -*- coding: utf-8 -*-

import elements
import enums
import os
import random

from classes import *

global compteur
compteur = 0
ended = False


def init(aMap):
	global map_
	map_ = aMap


#position and direction initialization
global x_init
x_init = 5
global y_init
y_init = 11

def robot_init():
	map_.setDirection(0,-1)
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

#######################################################################
#								 				python strategy																#
#######################################################################
def strat():
	cs = compassSensor.activate()
	ugSense = undergroundSensor.activate()
	gSense = groundSensor.activate()
	print("Facing " + cs + " in front of : " + gSense)
	objectHandler()
	if (gSense!="mur")&(gSense!="nothing"):
		lookAroundAndChoose()

	else:
		turningLeft = random.choice([True, False,True])
		if turningLeft:
			print("turning left...")
			turnLeft()
		else:
			print("turning right...")
			turnRight()


#######################################################################
#								 				strategy end																	#
#######################################################################

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
	

#user defined
def lookAroundAndChoose():
	gSense = groundSensor.activate()
	turningList = list()
	
	ugSenseForward = undergroundSensor.activate()
	gSense = groundSensor.activate()
	if ((gSense!="mur") & (ugSenseForward=="sol") & (gSense!="nothing")):
		#twice so it keeps going more often
		turningList.append("F")
		turningList.append("F")
	turnLeft()
	
	ugSenseLeft = undergroundSensor.activate()
	gSense = groundSensor.activate()
	if ((gSense!="mur") & (ugSenseLeft=="sol") & (gSense!="nothing")):
		turningList.append("L")
	turnLeft()
	
	#ugSenseBackward = undergroundSensor.activate()
	#gSense = groundSensor.activate()
	#if ((gSense!="mur") & (ugSenseBackward=="sol") & (gSense!="nothing")):
	#	turningList.append("B")
	turnLeft()

	ugSenseRight = undergroundSensor.activate()
	gSense = groundSensor.activate()
	if ((gSense!="mur") & (ugSenseRight=="sol") & (gSense!="nothing")):
		turningList.append("R")
	turnLeft()
	
	turning = random.choice(turningList)
	if turning=="F":
		objectHandler()
		walk()
	elif turning=="L":
		turnLeft()
		objectHandler()
		walk()
	#if turning=="B":
	#	turnLeft()
	#	turnLeft()
	#	walk()
	elif turning=="R":
		turnRight()
		objectHandler()
		walk()
	print("walking...")


#Function to destroy or update objects
def objectHandler():
	oSense = objectSensor.activate()

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
	elif oSense=="taocp":
		loveTaocp.activate()


