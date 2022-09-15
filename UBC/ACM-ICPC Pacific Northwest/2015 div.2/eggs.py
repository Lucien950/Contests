dropCount, floors = map(int, input().split())

maxDrop, minDrop = floors - 1, 2
for _ in range(dropCount):
	floors, safety = input().split()
	if safety == "SAFE": minDrop = max(minDrop, int(floors) + 1)
	else: maxDrop = min(maxDrop, int(floors) - 1)

print(minDrop, maxDrop)	