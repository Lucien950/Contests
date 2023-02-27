import sys
sys.setrecursionlimit(10000)
height, width = map(int, input().split())
maze = [list(input()) for _ in range(height)]

GATES = "ABCDEFGHIJKLMNOPQRSTUVW"
totalDots = sum([row.count(".") for row in maze])

# find entrance locations
playerLocations = {}
for y in range(height):
	for x in range(width):
		if maze[y][x] not in "X. ":
			playerLocations[maze[y][x]] = (x, y)

def solve(start):
	x, y = start
	foundPoints = 0
	if maze[y][x] == ".":
		foundPoints += 1
	maze[y][x] = "X"
	for dx, dy in [(0, 1), (1, 0), (-1, 0), (0, -1)]:
		newX, newY = x + dx, y + dy
		# boundary checking
		inBounds = 0 <= newX <= width - 1 and 0 <= newY <= height - 1
		if not inBounds: continue
		if maze[newY][newX] == "X": continue
		if maze[newY][newX] == "." or maze[newY][newX] == " ":
			foundPoints += solve((newX, newY))
		else:
			maze[newY][newX] = "X"
	return foundPoints



playerNeed = 0
foundDots = 0
for player, playerLocation in playerLocations.items():
	found = solve(playerLocation)
	if found != 0:
		playerNeed += 1
		foundDots += found
print(playerNeed, totalDots - foundDots)