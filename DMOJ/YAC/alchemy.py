from collections import defaultdict

# def solveOld(elements, elementCount):
# 	# O
# 	mapping = [-1 for _ in range(elementCount)] # all elements must be > 0

# 	solveOrder = sorted(list(range(elementCount)), key=lambda x: elements[x])
# 	elementCounters = Counter(elements)

# 	# first instance of every element number, as to point element number + 1
# 	firstInstance = {}
# 	for i, k in enumerate(elements):
# 		if k not in firstInstance:
# 			firstInstance[k] = i

# 	for solveIndex in solveOrder:
# 		# solved
# 		if mapping[solveIndex] != -1: continue
# 		loopSize = elements[solveIndex]
# 		# self looping
# 		if loopSize == 1:
# 			mapping[solveIndex] = solveIndex + 1 # oof
# 			continue

# 		needChildren = loopSize - 1
# 		totalLoopAmount = elementCounters[loopSize] 
# 		# check free point
# 		if needChildren in firstInstance:
# 			mapping[solveIndex] = firstInstance[needChildren] + 1 # oof
# 		# make loops
# 		elif totalLoopAmount % loopSize == 0:
# 			for loopStartIndex in range(solveIndex, solveIndex + totalLoopAmount, loopSize):
# 				for i in range(loopStartIndex, loopStartIndex + loopSize - 1):
# 					j = solveOrder[i]
# 					mapping[j] = solveOrder[i + 1] + 1 # oof
# 				# join the last one to the first one
# 				mapping[solveOrder[i + 1]] = solveOrder[loopStartIndex] + 1 # oof
# 		else:
# 			return -1

# 	if any([i == -1 for i in mapping]): return -1
# 	else: return " ".join(map(str, mapping))

def solve(elements, elementCount):
	mapping = [-1 for _ in range(elementCount)] # all elements must be > 0

	# elementIndexDict = defaultdict(list)
	elementIndexDict = [[] for _ in range(10**6+1)]
	for i, element in enumerate(elements): elementIndexDict[element].append(i)
	
	# for loopSize, elementIndexes in elementIndexDict.items():
	for loopSize, elementIndexes in enumerate(elementIndexDict):
		if len(elementIndexes) == 0:
			continue
		if loopSize == 1:
			for solveIndex in elementIndexes:
				mapping[solveIndex] = solveIndex + 1 # oof
			continue
		
		needChildren = loopSize - 1
		totalLoopAmount = len(elementIndexes)
		# check free point
		# if needChildren in elementIndexDict:
		if len(elementIndexDict[needChildren]) >= 1:
			firstLowerInstance = elementIndexDict[needChildren][0]
			for solveIndex in elementIndexes:
				mapping[solveIndex] = firstLowerInstance + 1 # oof
		# make loops
		elif totalLoopAmount % loopSize == 0:
			for loopStartIndex in range(0, len(elementIndexes), loopSize):
				for i in range(loopStartIndex, loopStartIndex + loopSize - 1):
					j = elementIndexes[i]
					mapping[j] = elementIndexes[i + 1] + 1 # oof
				# join the last one to the first one
				mapping[elementIndexes[i + 1]] = elementIndexes[loopStartIndex] + 1 # oof	
		else:
			return -1

	if any([i == -1 for i in mapping]): return -1
	else: return " ".join(map(str, mapping))

# I
elementCount = int(input())
elements = tuple(map(int, input().split()))
print(solve(elements, elementCount))

# from itertools import product
# for p in product(range(1, 5), repeat=4):
# 	sol, sol2 = solve(list(p), 4), solveNew(list(p), 4)
# 	if sol != sol2:
# 		print(p)
# 		print(sol, sol2)

# from random import randint
# e = []
# for i in range(100000):
# 	e.append(randint(1, 9))
# solve(e, 100000)