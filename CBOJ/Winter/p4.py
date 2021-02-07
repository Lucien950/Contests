import copy
import sys
h, w = map(int, input().split())
canvas = []
explored = [[False for i in range(w)] for j in range(h)]
for i in range(h):
    canvas.append(list(map(int, input().split())))
coloured = copy.deepcopy(canvas)
y1, x1, C, T = map(int, input().split())


#DFS
# sys.setrecursionlimit(1000000)
# def fill(x, y):
#     coloured[y-1][x-1] = C
#     explored[y-1][x-1] = True
#     for addX, addY in iter([(i, j) for i in range(-1, 2) for j in range(-1, 2)]):
#         #OUT OF BOUNDS TEST
#         newX, newY = addX + x, addY + y
#         if newX-1 < 0 or  newX > w or newY-1 < 0 or newY > h or (addX == 0 and addY == 0):
#             continue
#         if explored[newY-1][newX-1]:
#             continue
#         if abs(canvas[y-1][x-1]-canvas[newY-1][newX-1]) < T:
#             fill(newX, newY)
# fill(x1, y1)


# BFS
toFill = {(x1, y1)}
explored[y1-1][x1-1] = True
while toFill:
    x, y = toFill.pop()
    coloured[y - 1][x - 1] = C
    for addX, addY in iter(((-1, 0), (0, -1), (1, 0), (0, 1))):
        # OUT OF BOUNDS TEST
        newX, newY = addX + x, addY + y
        if newX - 1 < 0 or newX > w or newY - 1 < 0 or newY > h or (addX == 0 and addY == 0):
            continue
        if explored[newY - 1][newX - 1]:
            continue
        if abs(canvas[y-1][x-1]-canvas[newY-1][newX-1]) < T:
            explored[newY - 1][newX - 1] = True
            toFill.add((newX, newY))



print("\n".join([" ".join(map(str, row)) for row in coloured]))