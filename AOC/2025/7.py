# note that this code will assume that there are no instances of "^^"

from collections import defaultdict
from copy import deepcopy


lines = open("7.in").readlines()

# light_cols: set[int] = set()
pos: defaultdict[int, int] = defaultdict(int) # maps index to how many possibilities can exist there
pos[lines[0].index("S")] = 1

for line in lines[1:]:
	next_pos = deepcopy(pos)
	for col in pos:
		if line[col] == '^':
			next_pos[col + 1] += next_pos[col]
			next_pos[col - 1] += next_pos[col]
			next_pos[col] = 0
	pos = next_pos

print(sum(pos.values()))