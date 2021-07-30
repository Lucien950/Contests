from collections import defaultdict

houseCount = int(input())
adjList = defaultdict(list)
connectedCount = defaultdict(int)
for i in range(houseCount - 1):
	a, b = tuple(map(int, input().split()))
	adjList[a].append(b)
	adjList[b].append(a)
	connectedCount[b] += 1
	connectedCount[a] += 1


for houseNum in range(1, houseCount + 1):
	explored = defaultdict(False)
	explored[houseNum] = True

	nextLayer = []
	currentLayer = adjList[houseNum]

