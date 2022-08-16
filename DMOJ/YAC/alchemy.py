from collections import Counter
import sys
input = sys.stdin.readline

def solve(elements, elementCount):
	# O
	mapping = [-1 for _ in range(elementCount)] # all elements must be > 0

	solveOrder = sorted(list(range(elementCount)), key=lambda x: elements[x])
	elementCounters = Counter(elements)
	firstInstance = {}
	for i, k in enumerate(elements):
		if k not in firstInstance:
			firstInstance[k] = i
		if len(firstInstance) == 10:
			break

	for solveIndex in solveOrder:
		# solved
		if mapping[solveIndex] != -1: continue
		needChildren = elements[solveIndex] - 1
		# self looping
		if needChildren == 0:
			mapping[solveIndex] = solveIndex + 1 # oof
			continue
		
		# check free point
		if needChildren in firstInstance:
			mapping[solveIndex] = firstInstance[needChildren] + 1 # oof
		# make loops
		elif elementCounters[needChildren + 1] % (needChildren + 1) == 0:
			pairIndexes = solveOrder[solveIndex: solveIndex + elementCounters[needChildren + 1]]
			for startIndex in range(0, len(pairIndexes), needChildren + 1):
				sub = pairIndexes[startIndex: startIndex + needChildren + 1]
				for i, j in enumerate(sub[:-1]):
					mapping[j] = sub[i + 1] + 1 # oof
				# join the last one to the first one
				mapping[sub[-1]] = sub[0] + 1 # oof
		else:
			return -1

	if any([i == -1 for i in mapping]): return -1
	else: return " ".join(map(str, mapping))
# I
# elementCount = int(input())
# elements = list(map(int, input().split()))
# print(solve(elements, elementCount))

# from itertools import product
# for p in product(range(1, 5), repeat=4):
#     print(p)
#     sol = solve(list(p), 4)
#     if sol == -1: print(f"in {p} out {sol}")

from random import randint
e = []
for i in range(100000):
	e.append(randint(1, 9))
solve(e, 100000)