gatesCount = int(input())
freeGates = list(range(gatesCount + 1))
planeCount = int(input())
planes = [int(input()) for _ in range(planeCount)]

for planeNum, maxGate in enumerate(planes):
	left, right = 0, len(freeGates) - 1
	while left <= right:
		mid = (left + right) // 2
		if freeGates[mid] == maxGate: right, left = mid, mid; break
		elif freeGates[mid] > maxGate: right = mid - 1
		else: left = mid + 1
	if right == 0: # plane cannot land
		planeNum -= 1;break;
	freeGates.pop(right)
print(planeNum + 1)