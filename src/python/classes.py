#Defines a sensor.
class sensor:
	def __init__(self,map_, level_, range_):
		self.map_ = map_
		self.level_ = level_
		self.range_ = range_
	#gets the item in range on the map
	def activate(self):
		return self.map_.getItem(self.level_ , self.range_)

class compass:
	def __init__(self,map_):
		self.map_ = map_
	def activate(self):
		return self.map_.compass()

#defines an actuator
class actuator:
	def __init__(self,map_, level_, range_,newContent_):
		self.map_ = map_
		self.level_ = level_
		self.range_ = range_
		self.newContent_ = newContent_
	#Set the new item on the map
	def activate(self):
		self.map_.setItem(self.level_, self.range_, self.newContent_)
