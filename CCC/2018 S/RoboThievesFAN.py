from collections import deque
#handle input
line = input().split(" ")
h = int(line[0])
w = int(line[1])

grid = []

empty = []

#GRID SETUP
start = ()
for i in range(h):
    line = list(input())
    for j in range(w):
        if line[j] == 'W':
            continue
        elif line[j] == 'S':
            start = (i, j)
        elif line[j] == '.':
            empty.append([i,j])
    grid.append(line)

for i in range(len(grid)):
    for j in range(len(grid[i])):
        if grid[i][j] == 'C':
            for k in range(w):
                grid[i][k] = 'W'
            for l in range(h):
                grid[l][j] = 'W'

gridNums = [[-2 for j in range(w)] for i in range(h)]
for x, y in empty:
    gridNums[x][y] = -1

gridNums[start[0]][start[1]] = 0
toExplore = deque([(start, 0)])
while toExplore:
    (y, x), moveCount = toExplore.popleft()
    moves = ((0,1),(1,0),(-1, 0),(0, -1))
    for moveY, moveX in moves:
        newY, newX = y + moveY, x + moveX
        #if conveyor, do the conveyor thing

        if gridNums[newY][newX] != -1: continue
        gridNums[newY][newX] = moveCount + 1
        toExplore.append(((newY, newX), moveCount + 1))

[print(item) for row in gridNums for item in row if item != -2 and item != 0]