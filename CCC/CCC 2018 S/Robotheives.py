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
for row in range(r):
    toAdd = []
    for col in range(c):
        if maze[row][col] == ".":
            toAdd.append(-1)
        elif maze[row][col] == "S":
            toAdd.append(0)
            sr, sc = row,col
        else:
            if maze[row][col] == "W":
                toAdd.append("/")
            elif maze[row][col] == "C":
                toAdd.append("+")
            else:
                toAdd.append("-")
    stepMaze.append(toAdd)
#Place in Camera check areas
for row in range(r):
    for col in range(c):
        #Iterate through all the spaces to check for a camera
        if maze[row][col] == "C":
            for down, right in directions:
                #Iterate through every direction
                hitWall = False
                while not hitWall:
                    newRow = row + down
                    newCol = col + right

                    #Testing for wall/camera spot
                    if stepMaze[newRow][newCol] == -1:
                        stepMaze[newRow][newCol] = "-2"
                    elif maze[newRow][newCol] == "W":
                        hitWall = True
                        continue

                    #Shift over to continue to find the wall
                    if right == 0:
                        down += int(down/abs(down))
                    elif down == 0:
                        right += int(right/abs(right))


#------------------------------------------Processing------------------------------------------

def fill(curPos, distance):
    toExplore = []

    # Iterate in all directions
    for down, right in directions:
        newRow = curPos[0] + down
        newCol = curPos[1] + right

        #Check if out of bounds
        if newRow < 0 or newCol < 0:
            continue
        if newRow + 1 > r or newCol + 1 > c:
            continue

        #Interpret Location
        if stepMaze[newRow][newCol] == -1:
            stepMaze[newRow][newCol] = distance
            toExplore.append([newRow, newCol])
        elif stepMaze[newRow][newCol] == "-":
            conveyorMatch = {
                "U":[-1, 0],
                "D":[1,0],
                "R":[0,1],
                "L":[0,-1]
            }
            lookValue = maze[newRow][newCol]
            addRow, addCol = conveyorMatch[lookValue]
            if [newRow + addRow, newCol + addCol] != curPos and maze[newRow + addRow][newCol + addCol] != "W": #So it doesn't point to itself
                stepMaze[newRow + addRow][newCol + addCol] = distance
                toExplore.append([newRow + addRow, newCol + addCol])

    #Explore all toExplore locations
    for location in toExplore:
        fill(location, distance + 1)

fill([sr, sc], 1)

#------------------------------------------Output Handling------------------------------------------
banList = ["/", "+", "-"]
for row in stepMaze:
    for item in row:
        if item not in banList and item != 0: #not == Wall & not == Start(0)
            if item == "-2":
                print(-1)
            else:
                print(item)