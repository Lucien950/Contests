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

explored = [[False for _ in range(width)] for _ in range(height)]
floodfill(explored, {(0, 0)})
floodfill(explored, {(width-1, i)for i in range(height) if grid[i][width-1] == '.'})