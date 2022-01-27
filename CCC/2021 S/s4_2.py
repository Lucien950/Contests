from sys import stdin
from collections import defaultdict, deque

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
travelDistance = [lastStop - 1 + walkWeights[stations[lastStop]] for lastStop in range(1, n+1)]
for s1, s2 in swaps:
	station1OldDist = s1 - 1 + walkWeights[stations[s1]]
	station2OldDist = s2 - 1 + walkWeights[stations[s2]]
	travelDistance.remove(station1OldDist)
	travelDistance.remove(station2OldDist)

	temp = stations[s1]
	stations[s1] = stations[s2]
	stations[s2] = temp

	travelDistance.append(s1 - 1 + walkWeights[stations[s1]])
	travelDistance.append(s2 - 1 + walkWeights[stations[s2]])

	subOnly = stations.index(n)-1
	print(min(min(travelDistance), subOnly))