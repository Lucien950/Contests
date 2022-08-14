import copy
import itertools

def solve(length, a):
	if length <= 2: return sorted(a)
	optimalList = sorted(a)
	
	# Create two possible solutions
	oneIndex, twoIndex = a.index(optimalList[0]), a.index(optimalList[1])
	# smallest number first
	p1 = a[oneIndex:] + a[:oneIndex]
	# second smallest number second
	p2 = a[twoIndex-1:] + a[:twoIndex-1]

	# If the first two are already sorted, try to sort the next smallest number
	if p1 == p2:
		# work with only p1
		# find index of first non-sorted-conforming number
		for firstDifferent in range(length):
			if p1[firstDifferent] != optimalList[firstDifferent]:
				break
		if firstDifferent == length-1:
			# same list, no swaps
			pass
		else:
			sheesh = p1.index(optimalList[firstDifferent])
			p1[firstDifferent], p1[sheesh] = p1[sheesh], p1[firstDifferent]
		return p1
	
	sols = []
	# Counterexample solution for 2 1 3 4 5
	if oneIndex - twoIndex == 1 or twoIndex - oneIndex == length-1:
		# swap?
		p3 = a[oneIndex-1:] + a[:oneIndex-1]
		p3[0], p3[1] = p3[1], p3[0]
		sols.append(p3)
	
	# swap two conform first 2 elements
	secondIndex = p1.index(optimalList[1])
	p1[1], p1[secondIndex] = p1[secondIndex], p1[1]
	sols.append(p1)
	firstIndex = p2.index(optimalList[0])
	p2[0], p2[firstIndex] = p2[firstIndex], p2[0]
	sols.append(p2)

	return min(sols, key=lambda x: x[2])

def solveBrute(length, a):
	bestSol = a
	optimalSol = sorted(a)
	bestSolCoh = 0
	for i in range(len(bestSol)):
		if bestSol[i] == optimalSol[i]: bestSolCoh += 1
		else: break
	
	for i in range(length):
		for firstDifferent in range(length):
			if not a[firstDifferent] == optimalSol[firstDifferent]:
				break
		if firstDifferent == length - 1 and optimalSol == a:
			return a
		
		newA = copy.deepcopy(a)
		element = newA.index(optimalSol[firstDifferent])
		newA[firstDifferent], newA[element] = newA[element], newA[firstDifferent]
		for firstDifferent in range(length):
			if not newA[firstDifferent] == optimalSol[firstDifferent]:
				break
		if firstDifferent > bestSolCoh or (firstDifferent == bestSolCoh and newA[firstDifferent] < bestSol[firstDifferent]):
			bestSol = newA
			bestSolCoh = firstDifferent
		# rotate
		a = a[1:] + a[:1]
	return bestSol

length = int(input())
a = list(map(int, input().split()))
print(" ".join(map(str,solve(length, a))))

# BRUTE FORCE COMPARASION
# for i in itertools.permutations(range(1, 9), 5):
# 	i = list(i)
# 	if i[0] == 0: continue
# 	s1 = " ".join(map(str,solveBrute(5, i)))
# 	s2 = " ".join(map(str,solve(5, i)))
# 	if s1 != s2:
# 		print(f"Test Data {i}")
# 		print(f"Brute Force: {s1}, Algo: {s2}")
# 		break