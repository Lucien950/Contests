def solve():
	size, rookCount = map(int, input().split())
	rookPositions = [tuple(map(int, input().split())) for _ in range(rookCount)]
	rooksInRows, rooksInCols = [0 for _ in range(size)], [0 for _ in range(size)]

	for x, y in rookPositions:
		rooksInCols[y-1] += 1
		rooksInRows[x-1] += 1

	return "YES" if 0 in rooksInCols and 0 in rooksInRows else "NO"

	# this solves a much more interesting problem, but alas, it is not to be
	# if all >= 2 can be moved into a 0 row
	zeroRowExists = 0 in rooksInRows
	moved = False
	for rowRookCount in rooksInRows:
		if rowRookCount > 2:
			return "NO"
		if rowRookCount == 2 and zeroRowExists:
			if moved:
				return "NO"
			moved = True

	# if all >= can be moved into a 0 col
	zeroColsExist = 0 in rooksInCols
	moved = False
	for colRookCount in rooksInCols:
		if colRookCount > 2:
			return "NO"
		if colRookCount == 2 and zeroColsExist:
			if moved:
				return "NO"
			moved = True
	return "YES"

cases = int(input())
for case in range(cases):
	print(solve())