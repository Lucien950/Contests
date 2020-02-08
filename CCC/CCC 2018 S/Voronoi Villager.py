import math
vilNum = int(input())

class village():
	def __init__(self, location):
		self.location = location
	def getRange(self):
		order = locationList.index(self.location)
		if order == 0 or order == vilNum-1:
			return math.inf
		leftRange = (self.location - locationList[order-1]) / 2
		rightRange = (locationList[order + 1] - self.location) / 2
		return rightRange + leftRange

villageList = []
locationList = []
for i in range(vilNum):
	location = int(input())
	villageList.append(village(location))
	locationList.append(location)
locationList.sort()

rangeList = []
for vil in villageList:
	range = vil.getRange()
	rangeList.append(range)

print(sorted(rangeList)[0])