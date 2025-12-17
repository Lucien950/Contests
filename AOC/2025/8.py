from dataclasses import dataclass
from functools import reduce
from itertools import combinations
from math import dist
from operator import mul

# nodes and connections
nodes: list[list[int]] = [
	[int(x) for x in line.strip().split(",")]
	for line in open("8.in").readlines()
]

@dataclass
class UFNode:
	"""Represents a point with x and y coordinates."""
	parent: int
	size: int
	def __repr__(self):
		return f"({self.parent}, {self.size})"

uf: list[UFNode] = [UFNode(parent=i, size=0) for i in range(len(nodes))] # uf[i] = (parent, size of subtree)
def find(x: int) -> int:
	global uf
	if uf[x].parent != x:
		uf[x].parent = find(uf[x].parent)
		return uf[x].parent
	else:
		return x

connections: list[tuple[int, int]] = list(combinations(range(len(nodes)), 2))
connections.sort(key=lambda x: dist(nodes[x[0]],nodes[x[1]]))

for a,b in connections:
	a_parent = find(a)
	b_parent = find(b)
	if a_parent == b_parent:
		continue
	uf[b_parent].parent = a_parent
	uf[a_parent].size += uf[b_parent].size + 1

	if uf[a_parent].size == len(nodes) - 1:
		print(nodes[a][0] * nodes[b][0])
		break

parents = {find(i) for i in range(len(nodes))}
largest_groups: list[int] = sorted([uf[n].size + 1 for n in parents], reverse = True)
print(reduce(mul, largest_groups[:3]))