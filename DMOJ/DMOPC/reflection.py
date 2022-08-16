class Up:
	coords = [1, 0]
class Down:
	coords = [-1, 0]
class Left:
	coords = [0, -1]
class Right:
	coords = [0, 1]

def getReflectionDirection(mirror: str, direction: Up | Down | Left | Right) -> Up | Down | Left | Right:
	if mirror == "/":
		if direction == Up:
			return Left
		elif direction == Left:
			return Up
		elif direction == Down:
			return Right
		elif direction == Right:
			return Down
	elif mirror == "\\":
		if direction == Up:
			return Right
		elif direction == Right:
			return Up
		elif direction == Down:
			return Left
		elif direction == Left:
			return Down
	else:
		raise Exception("Invalid mirror")
def oppositeDirection(direction: Up | Down | Left | Right) -> Up | Down | Left | Right:
	if direction == Up:
		return Down
	elif direction == Down:
		return Up
	elif direction == Left:
		return Right
	elif direction == Right:
		return Left
	else:
		raise Exception("Invalid direction")

height, width = map(int, input().split())
grid = [list(input()) for _ in range(height)]
flipBoard = [[-1 for _ in range(width)] for _ in range(height)]
visited = [[False for _ in range(width)] for _ in range(height)]

def solve():
	global height, width, grid, flipBoard, visited
	if width == 1 or (width == 2 and height % 2 == 0):
		return -1
	
	bestFlips = float("inf")
	flipBoard[0][0] = 0
	visited[0][0] = True
	toExplore = [((0, 0), 0, Up)]
	while toExplore:
		location, flips, direction = toExplore.pop(0)
		mirror = grid[location[0]][location[1]]
		newDir = getReflectionDirection(mirror, direction)

		# 
		if location == (height - 1, width - 2) and direction == Down:
			if mirror == "/": flips += 1
			bestFlips = min(bestFlips, flips)
			continue

		# reflect
		newLocation = (location[0] + newDir.coords[0], location[1] + newDir.coords[1])
		# visited or out of bounds
		if visited[newLocation[0]][newLocation[1]] or newLocation[0] < 0 or newLocation[0] >= height or newLocation[1] < 0 or newLocation[1] >= width:
			continue
		toExplore.append((newLocation, flips, newDir))
		visited[newLocation[0]][newLocation[1]] = True
		
		# rotate mirror and reflect
		newLocation = (location[0] + newDir.coords[0] * -1, location[1] + newDir.coords[1] * -1)
		if visited[newLocation[0]][newLocation[1]] or newLocation[0] < 0 or newLocation[0] >= height or newLocation[1] < 0 or newLocation[1] >= width:
			continue
		toExplore.append((newLocation, flips + 1, oppositeDirection(newDir)))
		visited[newLocation[0]][newLocation[1]] = True
	
	return flipBoard[-1][-1]

print(solve())