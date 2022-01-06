import sys
from collections import defaultdict
input = sys.stdin.readline
height, width = map(int, (input().split()))
grid = [list(input()) for _ in range(height)]
steps = [[-1 for _ in range(width)] for _ in range(height)]
visited = [[False for _ in range(width)] for _ in range(height)]
# find start
for rowNum, row in enumerate(grid):
	if "S" in row:start = ((row.index("S"), rowNum), 0);break
# find cameras and find invalid locations
viewableFromCamera = [[False for _ in range(width)] for _ in range(height)]
cameraLocations = []
for rowNum, row in enumerate(grid):
	for colNum, col in enumerate(row):
		if col == "C": cameraLocations.append((colNum, rowNum))
for cameraLocation in cameraLocations:
	for cameraDelta in ((1,0),(0,1),(-1,0),(0,-1)):
		camCol, camRow = cameraLocation
		while 0 <= camCol < width and 0 <= camRow < height and grid[camRow][camCol] != "W":
			viewableFromCamera[camRow][camCol] = True
			camCol += cameraDelta[0]
			camRow += cameraDelta[1]
# precompute endpoints for conveyors
conveyorEndpoints = [[None for _ in range(width)] for _ in range(height)]
conveyorVisited = [[False for _ in range(width)] for _ in range(height)]
def findEndpoint(col, row):
	# dp
	if conveyorEndpoints[row][col] is not None: return conveyorEndpoints[row][col]
	
	conveyorVisited[row][col] = True
	direction = grid[row][col]
	# base case
	if direction == ".": return (col, row)
	# fuck switch case
	conveyorMap = defaultdict(lambda:-1,{"L":(-1,0), "R":(1,0), "U":(0,-1), "D":(0,1)})
	nudge = conveyorMap[direction]
	
	# check if we can move in the direction
	if nudge == -1 or not (0 <= col + nudge[0] < width and 0 <= row + nudge[1] < height):
		conveyorEndpoints[row][col] = -1
		return -1
	# on conveyor, let's find the endpoint
	if conveyorVisited[row+nudge[1]][col+nudge[0]] and conveyorEndpoints[row+nudge[1]][col+nudge[0]] is None:
		conveyorEndpoints[row][col] = -1
		return -1
	conveyorEndpoints[row][col] = findEndpoint(col + nudge[0], row + nudge[1])
	return conveyorEndpoints[row][col]
for rowNum, row in enumerate(grid):
	for colNum, col in enumerate(row):
		if col in ["L", "R", "U", "D"]:
			findEndpoint(colNum, rowNum)

toExplore = [start]
while toExplore:
	curr, weight = toExplore.pop(0)
	if visited[curr[1]][curr[0]]: continue
	if viewableFromCamera[curr[1]][curr[0]]: continue
	visited[curr[1]][curr[0]] = True
	steps[curr[1]][curr[0]] = weight
	for positionDelta in ((1,0),(0,1),(-1,0),(0,-1)):
		nextX, nextY = (curr[0] + positionDelta[0], curr[1] + positionDelta[1])

		# check if next position is in bounds
		if nextX < 0 or nextX >= width or nextY < 0 or nextY >= height: continue
		# Check conveyor
		if grid[nextY][nextX] in ["L", "R", "U", "D"]:
			newEnd = conveyorEndpoints[nextY][nextX]
			# ran into wall or camera or invalid endpoint
			if newEnd == -1:continue
			nextX, nextY = newEnd
		
		# check if next position is in bounds
		if nextX < 0 or nextX >= width or nextY < 0 or nextY >= height: continue
		# check if next position is a wall
		if grid[nextY][nextX] == "W": continue
		# check camera
		if viewableFromCamera[nextY][nextX]: continue
		# check if next position has been visited
		if visited[nextY][nextX]: continue
		toExplore.append(((nextX, nextY), weight + 1))

# OUTPUT
for rowNum, row in enumerate(steps):
	for colNum, item in enumerate(row):
		if grid[rowNum][colNum] == ".": print(steps[rowNum][colNum])

# TEST GRID (DEVELOPER FRIENDLY)
def twoString(a):
	if type(a) == int:
		if a < 10 and a != -1: return " " + str(a)
		return str(a)
	else:return a
print("\n".join([" ".join(map(twoString,[item if grid[rowNum][colNum] == "." else " "+grid[rowNum][colNum] for colNum, item in enumerate(row)])) for rowNum, row in enumerate(steps)]))