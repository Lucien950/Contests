from tkinter import Y


glasses = int(input())
threshold = int(input())

vertEdges = []
yVals = []
for x1, y1, x2, y2, colour in [tuple(map(int, input().split())) for _ in range(glasses)]:
    vertEdges.append((x1, y1, y2, colour))
    vertEdges.append((x2, y1, y2, colour))
    yVals.append(y1)
    yVals.append(y2)

vertEdges.sort(key=lambda x: x[0])
yVals.sort()
# compressed
atY = [0 for _ in range(len(yVals))]
deflateY = {yVals[i]: i for i in range(len(yVals))}

res = 0
for i, (x, y1, y2, tint) in enumerate(vertEdges):
    for y in range(deflateY[y1], deflateY[y2]):
        atY[y] += tint
    for j in 
print(res)