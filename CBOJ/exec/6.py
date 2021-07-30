from collections import defaultdict
from itertools import combinations

houseCount = int(input())

adjList = defaultdict(list)
connectedCount = defaultdict(int)
connectedEnds = defaultdict(list)
for i in range(houseCount - 1):
	a, b = tuple(map(int, input().split()))
	adjList[a].append(b)
	adjList[b].append(a)
	connectedCount[b] += 1
	connectedCount[a] += 1



def isEnd(n):
	return connectedCount[n] == 1

def dfs(n, depth = 0):
	if isEnd(n):
		if n in connectedEnds[starting] or starting in connectedEnds[n]:return
		global config
		config += max(0, depth - 3)
		connectedEnds[starting].append(n)
		connectedEnds[n].append(starting)

	for nextHouse in adjList[n]:
		if explored[nextHouse]:
			continue
		explored[nextHouse] = True
		dfs(nextHouse, depth + 1)

config = 0
for starting in range(1, houseCount + 1):
	explored = defaultdict(bool)
	explored[starting] = True
	dfs(starting)


# for house in range(1, houseCount + 1):
# 	#assume this house is a cultist house
# 	# nextLayer = adjList[house]
# 	# explored = defaultdict(bool)
# 	# explored[house] = True
# 	# while(nextLayer):
# 	# 	currentLayer = nextLayer
# 	# 	nextLayer = []
# 	#
# 	# 	goodHouses = 0
# 	# 	for thisHouse in currentLayer:
# 	# 		goodHouses += 1
# 	# 		[nextLayer.append(i) for i in adjList[thisHouse] if not explored[i]]
# 	# 		explored[thisHouse] = True
# 	#
# 	# 	#FOR THIS LAYER, there are this many valid configurations
# 	# 	configs += max(0, goodHouses - 3)
# 	# 	if(max(0, goodHouses - 3) >= 1):
# 	# 		print("with center", house, "and nodes", currentLayer)

# 10
# 1 2
# 2 3
# 1 5
# 5 4
# 5 6
# 5 7
# 7 8
# 7 9
# 9 10