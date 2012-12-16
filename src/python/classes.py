#global
map_ = False
ended = False

def walk():
	map_.goForward()

#Defines a sensor.
class sensor:
	def __init__(self,map_, level_, range_):
		self.map_ = map_
		self.level_ = level_
		self.range_ = range_
	def activate(self):
		return self.map_.getItem(self.level_ , self.range_)

#defines an actuator
class actuator:
	def __init__(self,map_, level_, range_,newContent_):
		self.map_ = map_
		self.level_ = level_
		self.range_ = range_
		self.newContent_ = newContent_
	
	def activate(self):
		self.map_.setItem(self.level_, self.range_, self.newContent_)
