grid = [list(map(lambda x: int(x) if x != "X" else x, input().split())) for _ in range(3)]
# fill in obvious 1s
# iterate through all rows, then all columns
keepGoing = True
while keepGoing:
    keepGoing = False

    # trivial solve
    for rowNum, row in enumerate(grid):
        xLoc = row.index("X") if "X" in row and row.count("X") == 1 else -1
        if xLoc != -1:
            if xLoc == 0:
                grid[rowNum][0]=2*grid[rowNum][1]-grid[rowNum][2]
            elif xLoc == 1:
                grid[rowNum][1]=(grid[rowNum][0]+grid[rowNum][2])//2
            elif xLoc == 2:
                grid[rowNum][2]=2*grid[rowNum][1]-grid[rowNum][0]
            keepGoing = True
    for colNum in range(3):
        col = [grid[i][colNum] for i in range(3)]
        yLoc = col.index("X") if "X" in col and col.count("X") == 1 else -1
        if yLoc != -1:
            if yLoc == 0:
                grid[0][colNum]=2*grid[1][colNum]-grid[2][colNum]
            elif yLoc == 1:
                grid[1][colNum]=(grid[0][colNum]+grid[2][colNum])//2
            elif yLoc == 2:
                grid[2][colNum]=2*grid[1][colNum]-grid[0][colNum]
            keepGoing = True

    # if all trivial solves are done
    if not keepGoing:
        # find if there is an X in grid
        xInGrid = any(["X" in row for row in grid])
        if not xInGrid: break #keyGoing = False, ALL GRIDS FILLED!

        # find a row or col with 2 Xs, and fill it with the same number thrice
        for rowNum, row in enumerate(grid):
            if row.count("X") == 2:
                fillNum = [i for i in row if i != "X"][0]
                for i in range(3): grid[rowNum][i] = fillNum
                keepGoing = True
                break 
        if keepGoing: continue
        for colNum in range(3):
            col = [grid[i][colNum] for i in range(3)]
            if col.count("X") == 2:
                fillNum = [i for i in col if i != "X"][0]
                for i in range(3): grid[i][colNum] = fillNum
                keepGoing = True
                break
    if sum([row.count("X") for row in grid]) == 9:
        grid = [[69 for _ in range(3)] for _ in range(3)]
        break
[print(" ".join(map(str, row))) for row in grid]