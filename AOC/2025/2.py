from functools import reduce
from itertools import combinations
from math import lcm

def get_multiples_between(a: int, b: int, m: int) -> int:
	"""
	Gets multiples of m between a and b, inclusive.
	"""
	return (b // m) - ((a - 1) // m)

def ceildiv(a: int, b: int) -> int:
	"""
	Performs ceiling division of a by b.
	"""
	return -(-a // b)

def sum_multiples_between(a: int, b: int, m: int) -> int:
	"""
	Gets the sum of multiples of m between a and b, inclusive.
	"""
	if a > b:
		return 0
	l = get_multiples_between(a,b, m)
	k= ceildiv(a, m)
	return m*(l*k + l*(l-1)//2)

def min_max_num_of_len(l: int) -> tuple[int, int]:
	"""
	Returns the minimum and maximum number with length l.
	"""
	return 10**(l-1), 10**l - 1

out = 0
for a,b in list(
	map(lambda x: tuple(map(int, x.split("-"))),
	 open("2.in").read().strip().split(",")
	)
):
	for l in range(len(str(a)), len(str(b)) + 1):
		lb, ub = min_max_num_of_len(l)
		if lb > b:
			break
		elif ub < a:
			continue
		valid_rep_lens = [rep_len for rep_len in range(1, l//2 + 1) if l % rep_len == 0]
		for combo_size in range(1, len(valid_rep_lens) + 1):
			for rls in combinations(valid_rep_lens, combo_size):
				ms = [int(("0" * (rl - 1) + "1") * (l//rl)) for rl in rls]
				m: int = reduce(lcm, ms, 1)
				x, y = max(lb, a), min(ub, b)
				cont = (-1)**(combo_size+1) * sum_multiples_between(x, y, m)
				out += cont

print(out)