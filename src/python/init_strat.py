#!/usr/bin/env python
# -*- coding: utf-8 -*-
import elements
import enums
import os

from classes import *


#movement functions
def walk(map_):
	map_.goForward()

def turnLeft(map_):
	map_.turnLeft()

def turnRight(map_):
	map_.turnRight()
	

