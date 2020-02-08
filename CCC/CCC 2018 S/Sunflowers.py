# Functions and Imports
import math


# Optimize me if you need to
def getSmallest(b):
    yee = [[b[0][0], 0], [b[0][N - 1], 1], [b[N - 1][0], 3], [b[N - 1][N - 1], 2]]
    yee.sort()
    return yee[0][1]


def rotateMatrix(mat, times):
    for i in range(times):
        # Consider all squares one by one
        for x in range(0, int(N / 2)):
            # Consider elements in group
            # of 4 in current square
            for y in range(x, N - x - 1):
                # store current cell in temp variable
                temp = mat[x][y]

                # move values from right to top
                mat[x][y] = mat[y][N - 1 - x]

                # move values from bottom to right
                mat[y][N - 1 - x] = mat[N - 1 - x][N - 1 - y]

                # move values from left to bottom
                mat[N - 1 - x][N - 1 - y] = mat[N - 1 - y][x]

                # assign temp to left
                mat[N - 1 - y][x] = temp


def displayMatrix(mat):
    for i in range(0, N):
        for j in range(0, N):
            print(mat[i][j], end=' ')
        print("")


# Initiate Board and Variables
N = int(input())
board = []
for i in range(N):
    add = input().split(" ")
    for i in range(len(add)):
        add[i] = int(add[i])
    board.append(add)

smalLoc = getSmallest(board)
# [0,0], [0,last], [last 0], [last last]
# 0 = nothing, 1 = left, 3 = right, 2 = 180d

rotateMatrix(board, smalLoc)
displayMatrix(board)