r, c = input().split(" ")
r, c = int(r), int(c)
sr, sc = 0, 0

# Make a maze of all the values
maze = []
for i in range(r):
    maze.append(list(input()))

##Make a separate maze for all the steps
stepMaze = []
for i in range(r):
    row = []
    for j in range(c):
        if maze[i][j] == ".":
            row.append(-1)
        elif maze[i][j] == "S":
            row.append(0)
            sr = i
            sc = j
        else:
            row.append("/")
    stepMaze.append(row)

# Making an adjacency list
adjList = []
#Up, Right, Down, Left; clockwise motion
directions = [[-1,0], [0,1], [1,0] ,[0,-1]]
for row  in range(r):
    for col in range(c):
        toAdd = []
        for down, right in directions:
            newRow = row + down
            newCol = col + right
            if newRow < 0 or newCol < 0:
                continue
            if newRow  + 1 > r or newCol + 1> c:
                continue

            typeList = "counting"
            if typeList == "counting":
                #Counting Grid
                toAdd.append(c * newRow + newCol)
            elif typeList == "absolute":
                #Absolute Position
                toAdd.append([newRow, newCol])
        adjList.append(sorted(toAdd))

for i in adjList:
    print(adjList.index(i), i)

q = []

banList = ["W", "L", "R", "U", "D"]
print(" ".join([item for row in stepMaze for item in row if item not in banList]))
