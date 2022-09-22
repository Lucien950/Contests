from collections import defaultdict
from itertools import combinations
from math import gcd

class Gear:
	def __init__(self, data) -> None:
		self.x = data[0]
		self.y = data[1]
		self.r = data[2]
		self.ratio = ()

gearCount = int(input())
gears = [Gear(tuple(map(int, input().split()))) for _ in range(gearCount)]
gears[0].ratio = (1, 1)

# populate adj list
adj = defaultdict(list)
for gearNum, otherGearNum in combinations(range(gearCount), 2):
	gear = gears[gearNum]
	otherGear = gears[otherGearNum]
	dsquare = (otherGear.x - gear.x)**2 + (otherGear.y - gear.y)**2
	distance = otherGear.r + gear.r
	connected = dsquare == distance ** 2
	if connected:
		adj[gearNum].append(otherGearNum)
		adj[otherGearNum].append(gearNum)

def solve():
	global adj, gears
	explored = {0}
	toExplore = [0]
	while toExplore:
		atGearIndex = toExplore.pop(0)
		atGear = gears[atGearIndex]
		for nextGearIndex in adj[atGearIndex]:
			nextGear = gears[nextGearIndex]
			if nextGear.ratio != ():
				if atGear.ratio[0]//abs(atGear.ratio[0]) == nextGear.ratio[0]//abs(nextGear.ratio[0]):
					# contact + direction wrong
					return "fighting"
			if nextGearIndex in explored:
				continue

			nextGear.ratio = (atGear.ratio[0] * atGear.r * -1, atGear.ratio[1] * nextGear.r)
			# reduce ratio
			ratioGCD = gcd(*nextGear.ratio)
			nextGear.ratio = tuple(map(lambda x: x//ratioGCD, nextGear.ratio))

			toExplore.append(nextGearIndex)
			explored.add(nextGearIndex)
	return gears[-1].ratio

ans = solve()
if ans == ():
	print("The input gear is not connected to the output gear.")
elif ans == "fighting":
	print("The input gear cannot move.")
else:
	print(":".join(map(str, ans)))