from collections import defaultdict
from heapq import heappop, heappush
from sys import stdin
input = stdin.readline


# a = """10 4 7
# 1 2 4 4
# 1 3 7 2
# 3 1 8 1
# 3 2 2 2
# 4 2 1 6
# 3 4 1 1
# 1 4 6 12
# 1 4
# """.splitlines()
# input = lambda : a.pop(0)


maxDamage, islandCount, routeCount = map(int, input().split())
adj = defaultdict(list)
for _ in range(routeCount):
	i, j, time, wear = tuple(map(int, input().split()))
	adj[i].append((j, time, wear))
	adj[j].append((i, time, wear))

start, end = map(int, input().split())


graph = [[float('inf') for _ in range(maxDamage + 1)] for _ in range(islandCount + 1)]
explore = [(0, start, maxDamage)]
while explore:
	time, at, damage = heappop(explore)

	
	old = graph[at][damage]
	if old <= time: continue
	else: graph[at][damage] = time
	if at == end: break

	for nextNode, pathTime, pathWear in adj[at]:
		newDamage = damage - pathWear
		if newDamage <= 0: continue
		heappush(explore, (time + pathTime, nextNode, newDamage))
# 1 indexing
ans = min(graph[end][1:])
print(-1 if ans == float('inf') else ans)