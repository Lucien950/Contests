steps = list(input())

grid = [[1,2],[3,4]]

def flipH(array):
    newGrid = []
    newGrid.append(array[1])
    newGrid.append(array[0])
    return newGrid

def flipV(array):
    newGrid = [[],[]]
    newGrid[0].append(array[0][1])
    newGrid[0].append(array[0][0])
    newGrid[1].append(array[1][1])
    newGrid[1].append(array[1][0])
    return newGrid

for i in steps:
    if i == "H":
        grid = flipH(grid)
    elif i == "V":
        grid = flipV(grid)
    else:
        raise Exception("Invalid Command in Input")

for row in grid:
    out = ""
    for item in row:
        out += str(item)
        out += " "
    print(out)