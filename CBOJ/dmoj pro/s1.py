# Voronoi Villages

villageCount = int(input())
villagePositions = sorted([int(input()) for _ in range(villageCount)])

minimum = float('inf')
for i in range(1, villageCount - 1):
    leftBound = (villagePositions[i - 1] + villagePositions[i]) /2
    rightBound = (villagePositions[i] + villagePositions[i + 1]) / 2
    totalInfluence = rightBound - leftBound
    minimum = min(minimum, totalInfluence)
print(str(round(minimum,2)))