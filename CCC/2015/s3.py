import math
gateCount = int(input())
planeCount = int(input())
planes = []
for i in range(planeCount):
	planes.append(int(input()))

# 1 INDEXED
freeGates = list(range(1, gateCount + 1))
planeCount = 0
for planeGate in planes:
	bottom = 0
	top = len(freeGates)-1
	while top-bottom > 1:
		half = math.ceil((top + bottom)/2)
		if freeGates[half] > planeGate:
			top = half
		else:
			bottom = half

	if freeGates[bottom] > planeGate:
		break
	else:
		if freeGates[top] > planeGate:
			#use bottom
			freeGates.pop(bottom)
		else:
			#use top
			freeGates.pop(top)
		planeCount += 1

# print(freeGates)
print(planeCount)