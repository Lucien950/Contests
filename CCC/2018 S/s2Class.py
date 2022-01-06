squareLength = int(input())
grid = [list(map(int, input().split())) for _ in range(squareLength)]
# rotate a 2d array 90 degrees clockwise
def rotate(grid):
    newGrid = [[0 for _ in range(squareLength)] for _ in range(squareLength)]
    for i in range(squareLength):
        for j in range(squareLength):
            newGrid[j][squareLength - 1 - i] = grid[i][j]
    return newGrid

for i in range(4):
    grid = rotate(grid)
    # test if top right corner of the grid is the smallest
    if min(grid[0]) == grid[0][0] and min([grid[i][0] for i in range(squareLength)]) == grid[0][0]:
        print("\n".join([" ".join(map(str,row)) for row in grid]))
        break