# input
height, width  = map(int, input().split())
grid = [input() for _ in range(height)]
qCount = int(input())
queries = [list(map(int, input().split())) for _ in range(qCount)]

# flood fill explored based on grid from top left
def floodfill(arr, initToExplore):
	toExplore = initToExplore
	while toExplore:
		x, y = toExplore.pop()
		if arr[y][x]: continue

		arr[y][x] = True
		for deltaX, deltaY in [[1, 0], [0, 1], [-1, 0], [0, -1]]:
			if 0 > x + deltaX or x + deltaX >= width or 0 > y + deltaY or y + deltaY >= height: continue
			if grid[y + deltaY][x + deltaX] == '#': continue
			toExplore.add((x + deltaX, y + deltaY))


direct = [[False for _ in range(width)] for _ in range(height)]
floodfill(direct, {(0, 0)})

# Vertically Connected / Horizontally Connected
HorizontalConnect = any([direct[i][-1] and direct[i][0] for i in range(len(direct))])
if not HorizontalConnect:
	rightFill = [[False for _ in range(width)] for _ in range(height)]
	floodfill(rightFill, {(width-1, i)for i in range(height) if grid[i][width-1] == '.'}) # every cell on the right side of the grid that is empty

VerticalConnect = any([i and j for i, j in zip(direct[0], direct[-1])])
if not VerticalConnect:
	bottomFill = [[False for _ in range(width)] for _ in range(height)]
	floodfill(bottomFill, {(i, height-1) for i in range(width) if grid[height-1][i] == '.'}) # every cell on the bottom side of the grid that is empty

# TESTING
# print("\n".join([" ".join(map(lambda x: "." if x else "#", row)) for row in explored]))
# print("----------------------------------------")
# print("\n".join([" ".join(map(lambda x: "." if x else "#", row)) for row in bottomFill]))
# print("----------------------------------------")
# print("\n".join([" ".join(map(lambda x: "." if x else "#", row)) for row in rightFill]))
# exit()


# SOLVE
for y, x in queries:
	# within the initial board (Very trivial)
	if 0 <= y < height and 0 <= x < width and direct[y][x]:
			print("yes")
			continue

	# outside board
	r, s = x%width, y%height
	if direct[s][r] == "#": print("no"); continue

	# horizontal traversal- Can you get to the correct horizontal coordinate
	# vertical traversal- Can you get to the correct vertical coordinate
	horizontalTraversal, verticalTraversal = False, False

	if 0 <= y < height: verticalTraversal = direct[s][r]
	if 0 <= x < width: horizontalTraversal = direct[s][r]
	horizontalTraversal = horizontalTraversal or HorizontalConnect or 0 <= x < width
	if not horizontalTraversal:
		# within one grid left of the centerboard
		if -width <= x < 0:
			if rightFill[s][r]:
				horizontalTraversal = True
	verticalTraversal = verticalTraversal or VerticalConnect or 0 <= y < height
	if not verticalTraversal:
		# within one grid above the centerboard
		if -height <= y < 0:
			if bottomFill[s][r]:
				verticalTraversal = True
	print("yes") if horizontalTraversal and verticalTraversal else print("no")