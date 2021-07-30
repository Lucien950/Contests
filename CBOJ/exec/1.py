import math

stationCount = int(input())

coordinates = []
for stationI in range(stationCount):
	x, y = map(int, input().split())
	coordinates.append((x, y))


def distanceGreaterThan(cord1, cord2, n):
	x1, y1 = cord1
	x2, y2 = cord2
	return n > math.sqrt((x2-x1)**2 + (y2-y1)**2)

