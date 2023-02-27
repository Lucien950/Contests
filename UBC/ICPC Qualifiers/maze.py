height, width = map(int, input().split())
maze = [list(input()) for _ in range(height)]

playerCountRequired = 0
foundDots = 0
GATES = "ABCDEFGHIJKLMNOPQRSTUVW"
# find entrance locations
playerLocations = {}
for y in range(height):
	for x in range(width):
		sheeeesh = maze[y][x]
		if sheeeesh not in "X .":
			playerLocations[sheeeesh] = (x, y)
# print(playerLocations)
# flood fill
explored = [[False for _ in range(width)] for _ in range(height)]
for starter, starterLocation in playerLocations.items():
	# check if the starterlocation is unnecessary
	if starterLocation == None: continue
	# print(f"checking {starter}")
	playerCountRequired += 1
	toExplore = {starterLocation}
	localFoundDots = 0

	while toExplore:
		x, y = toExplore.pop()
		for dx, dy in [(0, 1), (1, 0), (-1, 0), (0, -1)]:
			newX, newY = x + dx, y + dy
			# boundary checking
			inBounds = 0 <= newX <= width - 1 and 0 <= newY <= height - 1
			if not inBounds: continue
			
			# can move here
			if maze[newY][newX] in " ." and not explored[newY][newX]:
				toExplore.add((newX, newY))
				explored[newY][newX] = True
				if maze[newY][newX] == ".":
					localFoundDots += 1
			# mute gates
			if (maze[newY][newX] != "X") and (maze[y][x] in " ."):
				assert(maze[newY][newX] in playerLocations)
				playerLocations[maze[newY][newX]] = None
	# dead end detection
	if localFoundDots == 0:
		playerCountRequired -= 1
	foundDots += localFoundDots

# calculate total amount of 
totalDots = sum([row.count(".") for row in maze])
unFoundDots = totalDots - foundDots

print(playerCountRequired, unFoundDots)