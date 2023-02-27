from itertools import product
from math import floor
from progress.bar import Bar

def solve1(a, b, c):
	ops = [
		lambda x,y: x + y,
		lambda x,y: x - y,
		lambda x,y: x // y if x%y==0 else Exception("NOT ALLOWED"),
		lambda x, y: x * y
	]
	smallest = float('inf')
	for op1, op2 in product(ops, repeat=2):
		try:
			res = op2(op1(a, b), c)
			assert(res >= 0)
			smallest = min(smallest, res)
		except: pass

	assert(smallest == floor(smallest))
	return smallest

def solve2(digits: list[int]):
	def solve(i: int, res: int):
		if i >= 3:
			return res if res >= 0 else float("inf")
		
		return min(
			solve(i+1, res + digits[i]),
			solve(i+1, res - digits[i]),
			solve(i+1, res // digits[i]) if res%digits[i]==0 else float('inf'),
			solve(i+1, res * digits[i])
		)
	return solve(1, digits[0])


bar = Bar('Processing', max=1000**3)
for l, m, n in product(range(1, 1001), repeat=3):
	sol1 = solve1(l, m, n)
	sol2 = solve2([l, m, n])
	if sol1 != sol2:
		print(l, m, n)
	bar.next()