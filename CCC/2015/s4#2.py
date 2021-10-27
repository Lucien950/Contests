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

# graph[node][damage]
graph = [[float('inf') for i in range(wall + 1)] for j in range(islands + 1)]
explore = [(0, start, wall)]
while explore:
	time, at, wallDepth = heappop(explore)

	old = graph[at][wallDepth]
	if old <= time:
		continue
	else:
		graph[at][wallDepth] = time

	if at == end:
		break
	for nextNode, pathTime, pathWear in adj[at]:
		newWall = wallDepth - pathWear
		if newWall <= 0:
			continue

		heappush(explore, (time + pathTime, nextNode, newWall))

# [print(i) for i in graph]
ans = min(graph[end][1:])
print(ans if ans != float('inf') else -1)