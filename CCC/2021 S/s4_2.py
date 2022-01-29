from sys import stdin, stdout
from collections import defaultdict, deque
import heapq

# f = open("./CCC/2021 S/senior_data/s4/s4.4-31.in", "r")
# input = f.readline
input = stdin.readline

# INT INPUT
n, w, d = map(int, input().split())

# WALKWAY 
walkAdj = defaultdict(list)
for _ in range(w):
	to, f = map(int, input().split())
	walkAdj[f].append(to)
# Amount of time required to navigate to the end from a given node using only walkways
walkWeights = [float('inf') for _ in range(n + 1)]
walkWeights[-1]=0
queue = deque()
queue.append(n)
visited = [False for _ in range(n + 1)]
while queue:
	node = queue.popleft()
	for next in walkAdj[node]:
		if visited[next]: continue
		walkWeights[next] = walkWeights[node] + 1
		visited[next] = True
		queue.append(next)

stations = [0]+list(map(int,input().split()))
# unordered list of all travel distance. Order is not relevent when looking for minimum
travelDistance = []
for lastStop in range(1, n+1):
	heapq.heappush(travelDistance, (
		lastStop - 1 + walkWeights[stations[lastStop]],
		lastStop,
		stations[lastStop]
	))

out = []
lastStationIndex = stations.index(n)
for _ in range(d):
	s1, s2 = map(int, input().split())

	if stations[s1] == n:
		lastStationIndex = s2
	elif stations[s2] == n:
		lastStationIndex = s1
	
	station1OldDist = s1 - 1 + walkWeights[stations[s1]]
	station2OldDist = s2 - 1 + walkWeights[stations[s2]]

	stations[s1], stations[s2] = stations[s2], stations[s1]

	heapq.heappush(travelDistance, (
		s1 - 1 + walkWeights[stations[s1]],
		s1,
		stations[s1],
	))
	heapq.heappush(travelDistance, (
		s2 - 1 + walkWeights[stations[s2]],
		s2,
		stations[s2],
	))

	while True:
		# ans[0] returns the smallest time (thanks heapq)
		time, index, station = travelDistance[0]
		# Is this still a valid station (did no swaps affect it)
		if stations[index] == station:
			subOnly = lastStationIndex - 1
			out.append(str(min(subOnly, time)))
			break
		# If it is invalid, remove it
		heapq.heappop(travelDistance)

stdout.write('\n'.join(out))