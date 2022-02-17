data = """8 10
0 2 5 5 6 9 0 0
""".split("\n")
# data = ["0 5", "0 2 3"]
input = lambda : data.pop(0)

from math import ceil, floor
from itertools import combinations

pointCount, circum = map(int, input().split())
rawLocations = list(map(int, input().split()))
locations = sorted(list(set(rawLocations)))
occupied = [(i, False) for i in range(circum)]
countOccupiers = [0 for _ in range(circum)]
for location in locations:
    occupied[location] = (location, True)
for location in rawLocations:
    countOccupiers[location] += 1

def triangles(l, r, reverse):
    arr = []
    if reverse:
        print("REVERSE")
        arr = occupied[:r+1] + occupied[l:]
    else:
        l, r = min(l, r), max(l, r)
        arr =  occupied[l + 1:r]
    
    returnVal = 0
    for i, occupy in arr:
        if occupy:
            returnVal += countOccupiers[i]
    return returnVal
lineOffset = circum / 2
makeLine = False
if lineOffset == int(lineOffset): makeLine = True

solutions = 0
for point1, point2 in combinations(locations, 2):
    # if point1 and point2 make a line which intersects the center of the circle
    if makeLine and point2 - point1 == lineOffset: continue

    up = point2 - point1 < lineOffset
    # get range where points are valid
    a, b = (point1 + lineOffset)%circum, (point2 + lineOffset)%circum
    if(up):
        a, b = ceil(a), floor(b)
    else:
        b, a = floor(a), ceil(b)
    print(f"({point1}-{point2}) checking between ({a}-{b})")
    hereSol = countOccupiers[point1] * countOccupiers[point2] * triangles(a, b, b < a and 0 not in [a, b]) #todo sort this out
    if hereSol:
        print(f"found {hereSol} solutions")
    solutions += hereSol

print(solutions)