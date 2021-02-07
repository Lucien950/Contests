triSize, subSize = map(int, input().split())
tri = []
for row in range(triSize): tri.append(list(map(int, input().split())))

nodes = []
for rowNum, row in enumerate(tri):
    for i, element in enumerate(row):
        if rowNum == len(tri)-1: break
        pass

#computing