from itertools import product
from math import floor

a, b, c = map(int, input().split())
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
print(smallest)