from collections import defaultdict, deque
from sys import stdin
input = stdin.readline

row = int(input())
col = int(input())

# Gives all the neighbours given a cell number
# for example, if row * col = 12, it will provide the position of all the 12s on the board
indexOF = defaultdict(list)
for rowNum in range(row):
	nextRow = list(map(int, input().split()))
	for colNum, val in enumerate(nextRow):
		indexOF[val].append((colNum, rowNum))

def explore():
	explored = [[False for _ in range(col)] for _ in range(row)]
	toExplore = deque()
	toExplore.append((row-1, col-1))
	while toExplore:
		x, y = toExplore.popleft()
		neighbours = indexOF[(x+1)*(y+1)]
		for nextx, nexty in neighbours:
			if nextx >= col or nexty >= row: continue #catch out of bounds
			if explored[nexty][nextx]: continue
			if nexty == 0 and nextx == 0: return "yes"
			explored[nexty][nextx] = True
			toExplore.append((nextx, nexty))
	return "no"

print(explore())