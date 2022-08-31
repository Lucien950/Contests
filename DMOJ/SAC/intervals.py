data = """4 3
7 9
-5 4
10 14
16 19
8 10
-5 -5
11 18
""".split("\n")
input = lambda: data.pop(0)

intervalCount, queryCount = map(int, input().split())
intervals = sorted([tuple(map(int, input().split())) for _ in range(intervalCount)], key=lambda x: x[0])
queries = [tuple(map(int, input().split())) for _ in range(queryCount)]

# This assumes no overlap in intervals
flattenedInterval = [num for interval in intervals for num in interval]
startOrEnd = ["s" if (i == 0) else "e" for interval in intervals for i, num in enumerate(interval)]

def bSearch(find):
	l, r = 0, len(flattenedInterval) - 1
	while l < r:
		mid = (l + r)//2
		if flattenedInterval[mid] < find:
			l = mid + 1
		else:
			r = mid
	assert(l == r)
	return (l, flattenedInterval[l])

for query in queries:
	# find an interval start
	leftInterval, val = bSearch(query[0])
	if val != query[0]: leftInterval -= 1
	# find an interval end
	rightInterval, val = bSearch(query[1])
	print(leftInterval, rightInterval)
	# if in same interval, pass
	# else if in different connected intervals, pass
	# else fail