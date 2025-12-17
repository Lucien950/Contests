from itertools import product

lines = [list(l.strip()) for l in open("4.in").readlines()]

def inrange(i, j) -> bool:
	"""
	Check if (i, j) is in range of lines
	"""
	return 0 <= i < len(lines) and 0 <= j < len(lines[0])

def get_check_squares(i, j) -> list[tuple[int, int]]:
	"""
	Get all squares around (i, j) that are in range
	"""
	dx = [-1,0,1]
	dy = [-1,0,1]
	return [
		(i+dy, j+dx)
		for dx, dy in product(dx, dy)
		if not (dx == dy == 0) and inrange(i+dy, j+dx)
	]

out = 0
check: set[tuple[int, int]] = set()
# initial fill
for i, line in enumerate(lines):
	for j in range(len(line)):
		if lines[i][j] != '@':
			continue
		neighbour_has = [(a,b) for a,b in get_check_squares(i, j) if lines[a][b] == '@']
		if len(neighbour_has) < 4:
			out += 1
			check.update(neighbour_has)
			lines[i][j] = '.'

while check:
	i, j = check.pop()
	if lines[i][j] != '@':
		continue
	neighbour_has = [(a,b) for a,b in get_check_squares(i, j) if lines[a][b] == '@']
	if len(neighbour_has) < 4:
		out += 1
		check.update(neighbour_has)
		lines[i][j] = '.'
print(out)

# write lines to file
with open("4.out", "w") as f:
	for line in lines:
		f.write("".join(line) + "\n")
