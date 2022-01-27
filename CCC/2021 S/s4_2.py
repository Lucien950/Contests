from sys import stdin
from collections import defaultdict, deque
import heapq

input = stdin.readline
n, w, d = map(int, input().split())
walkways = [tuple(map(int, input().split())) for _ in range(w)]
stations = [0]+list(map(int,input().split()))
swaps =[tuple(map(int, input().split())) for _ in range(d)]

walkAdj = defaultdict(list)
for to, f in walkways:
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

# unordered list of all travel distance. Order is not relevent when looking for minimum
travelDistance = []
for lastStop in range(1, n+1):
	heapq.heappush(travelDistance, (
		lastStop - 1 + walkWeights[stations[lastStop]],
		lastStop,
		stations[lastStop]
	))

for s1, s2 in swaps:
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
			subOnly = stations.index(n)-1
			print(min(subOnly, time))
			break
		# If it is invalid, remove it
		heapq.heappop(travelDistance)
