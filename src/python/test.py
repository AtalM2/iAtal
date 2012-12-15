#!/usr/bin/env python
# -*- coding: utf-8 -*-

import sys
sys.path.append(".libs")
import elements
import enums

#globals
ended = False
compteur = 0

#stratégie python
def strat(aMap):
#	print (aMap.hello())

	print(elements.getItem(layer.level.Underground,0))
	global ended
	ended = True
'''
	#case_avant = controller.getCaseAvant()
	if case_avant == "herbe":
		return "avance"
	else:
		global compteur
		compteur += 1
		if compteur > 10:
			global ended
			ended = True
		return "tourne_gauche"
'''
#sert à savoir si la strat est finie ou non
def isEnded():
	return ended;


#pour mémoire
def func(a) :
	if a == "herbe":
		x = "vas y roule"
	else:
		x = "n'y va pas !"
	return (x)
