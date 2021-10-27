from collections import defaultdict
from sys import stdin
from heapq import *
input = stdin.readline


adj = defaultdict(list)

wall, islands, routes = map(int, input().split())
for i in range(routes):
	i1, i2, time, wear = map(int, input().split())
	adj[i1].append((i2, time, wear))
	adj[i2].append((i1, time, wear))
start, end = map(int, input().split())


# (time, at, wallLeft)
toExplore = [(0, start, wall)]
bestTime = float('inf')
bests = []

# (time, wallLeft)
# also 1 indexed (oops)
bestVals = [(float('inf'), float('inf'))] * (islands + 1)

while toExplore:
	time, at, wallLeft = heappop(toExplore)

	# "base cases"
	if time > bestTime:
		continue
	if at == end:
		bestTime = min(bestTime, time)
		break

	# [BV]
	if time > bestVals[at][0] and wallLeft > bestVals[at][1]:
		continue
	elif time == bestVals[at][0] :
		continue

	# update bestVals array
	bestVals[at] = (time, wallLeft)


	for nextPath in adj[at]:
		to, pathTime, wear = nextPath
		newWall = wallLeft - wear
		if newWall <= 0: continue
		heappush(toExplore, (time + pathTime, to, newWall))


# something here
# print(bestVals)
print(bestTime) if bestTime != float("inf") else print(-1)