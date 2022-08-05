length = int(input())
a = list(map(int, input().split()))

def solve():
	global length, a

	if length <= 2:
		return sorted(a)
	
	optimalList = sorted(a)
	# problem line
	oneIndex, twoIndex = a.index(optimalList[0]), a.index(optimalList[1])

	# smallest number first
	p1 = a[oneIndex:] + a[:oneIndex]
	# second smallest number second
	p2 = a[twoIndex-1:] + a[:twoIndex-1]

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
	else:
		if(p1[2]>p2[2]):
			# use p2
			firstIndex = p2.index(optimalList[0])
			p2[0], p2[firstIndex] = p2[firstIndex], p2[0]
			return p2
		else:
			# use p1
			secondIndex = p1.index(optimalList[1])
			p1[1], p1[secondIndex] = p1[secondIndex], p1[1]
			return p1

print(" ".join(map(str,solve())))