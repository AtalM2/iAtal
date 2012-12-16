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

#sert à savoir si la strat est finie ou non
def isEnded():
	return ended;	

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



