from copy import deepcopy
from itertools import product


gridWidth, gridHeight, blurTimes = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(gridHeight)]
blurGrid = [[None for _ in range(gridWidth)] for _ in range(gridHeight)]

for _ in range(blurTimes):
	for i, j in product(range(gridHeight), range(gridWidth)):
		blurGrid[i][j] = sum([grid[(i + deltaHeight) % gridHeight][(j + deltaWidth) % gridWidth] for deltaHeight, deltaWidth in product((-1, 0, 1), repeat = 2)])
	grid = deepcopy(blurGrid)
# print("\n".join([" ".join(map(lambda x: str(x/9), row)) for row in blurGrid]))
print(len(set([i for row in blurGrid for i in row])))