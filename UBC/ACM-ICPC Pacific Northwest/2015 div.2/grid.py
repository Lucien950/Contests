from itertools import product

gridHeight, gridWidth = map(int,input().split())
grid = [list(map(int, list(input()))) for _ in range(gridHeight)]

# shit DP approach
def dpSolve():
	global gridHeight, gridWidth, grid
	dp = [[float('inf') for _ in range(gridWidth)] for _ in range(gridHeight)]
	dp[0][0] = 0

	for height, width in product(range(gridHeight), range(gridWidth)):
		if not dp[height][width] < float('inf'):
			continue
		strideLength = grid[height][width]
		for normalDeltaH, normalDeltaW in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
			normalDeltaH, normalDeltaW = map(lambda x: x * strideLength, (normalDeltaH, normalDeltaW))
			newHeight, newWidth = height + normalDeltaH, width + normalDeltaW
			if 0 <= newHeight < gridHeight and 0 <= newWidth < gridWidth:
				dp[newHeight][newWidth] = min(dp[newHeight][newWidth], dp[height][width] + 1)

	print(dp[-1][-1] if dp[-1][-1] < float('inf') else "IMPOSSIBLE")

explored = set()
toExplore = [(0, 0, 0)]
sol = None
while toExplore:
	height, width, steps = toExplore.pop(0)
	strideLength = grid[height][width]
	for normalDeltaH, normalDeltaW in [(1, 0), (-1, 0), (0, 1), (0, -1)]:
		normalDeltaH, normalDeltaW = map(lambda x: x * strideLength, (normalDeltaH, normalDeltaW))
		newHeight, newWidth = height + normalDeltaH, width + normalDeltaW
		
		# check out of bounds
		if not (0 <= newHeight < gridHeight and 0 <= newWidth < gridWidth): continue
		
		# check if win
		if newHeight == gridHeight - 1 and newWidth == gridWidth - 1:
			sol = steps + 1
			break

		if (newHeight, newWidth) not in explored:
			toExplore.append((newHeight, newWidth, steps + 1))
			explored.add((newHeight, newWidth))
	if sol:
		break
print(sol if sol else "IMPOSSIBLE")