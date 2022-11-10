from math import ceil
def solve():
	aSize = int(input())
	a = sorted(list(map(int, input().split())))
	if aSize <= 1: return 1

	k = ceil(aSize/2) # k must be between 0 and aSize, as if any more, she would have to delete non-existant numbers
	
	# find which values of a are larger than k
	leftK = 0
	rightK = aSize - 1
	while leftK < rightK - 1:
		mid = (leftK + rightK)//2
		if a[mid]<=k:
			leftK = mid
		else:
			rightK = mid
	
	if leftK == 0 and a[0] > 1: return 0
	return ceil((leftK + 2)/2)

cases = int(input())
for case in range(cases):
	print(f"{solve()}")