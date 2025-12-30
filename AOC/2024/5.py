from collections import defaultdict


lines = open("5.in").readlines()

i = 0

post_illegals_for: defaultdict[int, set[int]] = defaultdict(set)
children: defaultdict[int, list[int]] = defaultdict(list)
nodes = set()
while (l := lines[i].strip()) != '':
	a,b = map(int, l.split("|"))
	# a must come before b if they both appear
	# namely b ... a combination is CANNOT possible
	post_illegals_for[b].add(a)
	children[a].append(b)
	i += 1
i += 1

def toposort(pnums: list[int]):
	continuations: dict[int, list[int]] = {}
	visited: set[int] = set()

	def topo(at: int, out: list[int]):
		if at in continuations:
			out.extend(continuations[at])
			del continuations[at]
		if at in visited: return
		visited.add(at)
		nexts = set(children[at]).intersection(pnums)
		for n in nexts:
			topo(n, out)
		out.append(at)

	for p in pnums[1:]:
		if p in visited:
			continue
		out: list[int] = []
		topo(p, out)
		continuations[p] = out

	assert len(continuations.keys()) == 1, f"length of continuation keys is {len(continuations.keys())}"
	return continuations[list(continuations.keys())[0]]

out = 0
for li in range(i, len(lines)):
	pnums = list(map(int, lines[li].strip().split(",")))
	# check if not correctly ordered, continue it
	# we will assume that the page numbers are unique in pnums
	assert len(set(pnums)) == len(pnums)

	# if at any point the query sees an element in this list, we fail!!!
	i_hope_not_to_see: set[int] = set()
	ok = True
	bad_count = 0
	for p in pnums:
		if p in i_hope_not_to_see:
			ok = False
			break
		i_hope_not_to_see |= post_illegals_for[p]

	if not ok:
		final_order = toposort(pnums)
		out += final_order[len(pnums)//2]

print(out)