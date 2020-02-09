#------------------------------------------Input Handling------------------------------------------
#Global Variables
r, c = input().split(" ")
r, c = int(r), int(c)
sr, sc = 0, 0
#Up, Right, Down, Left; clockwise motion
directions = [[-1,0], [0,1], [1,0] ,[0,-1]]
maze = []
stepMaze = []
adjList = []

#----------------Make a maze of all the values----------------
for i in range(r):
    maze.append(list(input()))

#---------------------Make a separate maze for all the steps(this is output-ish)----------------
for i in range(r):
    row = []
    for j in range(c):
        if maze[i][j] == ".":
            row.append(-1)
        elif maze[i][j] == "S":
            row.append(0)
            sr, sc = i,j
        else:
            row.append("/")
    stepMaze.append(row)


#------------------------------------------Processing------------------------------------------

def fill(curPos, distance):
    toExplore = []
    for down, right in directions:
        newRow = curPos[0] + down
        newCol = curPos[1] + right
        if newRow < 0 or newCol < 0:
            continue
        if newRow + 1 > r or newCol + 1 > c:
            continue
        if stepMaze[newRow][newCol] == -1:
            stepMaze[newRow][newCol] = distance
            toExplore.append([newRow, newCol])
    for location in toExplore:
        fill(location, distance + 1)

fill([sr, sc], 1)

#------------------------------------------Output Handling------------------------------------------
for row in stepMaze:
    for item in row:
        if item != "/" and item != 0: #not == Wall & not == Start(0)
            print(item)