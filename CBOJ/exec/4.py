import math
from collections import defaultdict

lenScary, lenFun = map(int, input().split())
scary = input()
fun = input()
positions = defaultdict(list)
[positions[i].append(j) for j, i in enumerate(scary)]



yes = True
set(scary)
for i in set(fun):
	if i not in scary:
		yes = False
		break

if not yes:
	print(-1)

else:
	#determine first letter
	toExplore = [(i, 1, 0) for i in positions[fun[0]]]
	bestCost = math.inf
	#BFS
	while toExplore:
		#where are we, index we are looking for in the fun word, totalcost of the maneuver
		position, funPosition, cost = toExplore.pop(0)
		if cost > bestCost - 1:
			continue

		if funPosition == lenFun:
			bestCost = min(cost, bestCost)
			continue

		#left
		if position - 1 >= 0 and scary[position - 1] == fun[funPosition]:
			toExplore.append((position - 1, funPosition + 1, cost + 1))
		#right
		if position + 1 < lenScary and scary[position + 1] == fun[funPosition]:
			toExplore.append((position + 1, funPosition + 1, cost + 1))

		#teleport
		for otherPosition in positions[scary[position]]:
			if position != otherPosition:
				toExplore.append((otherPosition, funPosition, cost + abs(position - otherPosition)))
	if bestCost == math.inf:
		print(-1)
	else:
		print(bestCost)