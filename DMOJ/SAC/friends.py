from collections import defaultdict
from math import floor, log2

class UnionFind():
	root = []
	def __init__(self, size) -> None:
		self.root = [i for i in range(size)]
	def getRoot(self, a):
		parent = self.root[a]
		if parent == a: return a
		self.root[a] = self.getRoot(parent)
		return self.root[a]
	def isJoined(self, a, b): return self.getRoot(a) == self.getRoot(b)
	def join(self, a, b):
		rootA, rootB = uf.getRoot(a), uf.getRoot(b)
		if rootA != rootB:
			self.root[rootB] = rootA
class SparseTable():
	def __init__(self, a) -> None:
		self.a = a
		self.length = len(a)
		# 2**p is the largest power of two smaller than the length of the array
		self.p = floor(log2(self.length))
		self.st = [[] for _ in range(self.p + 1)]
		self.buildSparseTable()
		# floorLog2 precomputation
		self.floorLog2 = [0 for _ in range(self.length + 1)]
		for i in range(2, self.length + 1):
			# does this work???
			self.floorLog2[i] = self.floorLog2[i/2] + 1
	def buildSparseTable(self):
		# fill first row
		self.st[0] = self.a
		# consider 2**p (important)
		for p in range(1,self.p + 1):
			for i in range(self.length - 2**p + 1):
				l, r = i, i + 2**(p-1)
				self.st[p].append(min(map(lambda x: self.st[p-1][x], (l, r))))
	def min(self, l, r):
		queryLength = r - l + 1
		p = floor(log2(queryLength))
		left = self.st[p][l]
		right = self.st[p][r - 2**p + 1]
		return min(left, right)

studentCount, queryCount = map(int, input().split())
friendShips = [tuple(map(int, input().split())) for _ in range(studentCount - 1)]
queries = reversed([map(int, input().split()) for _ in range(queryCount)])


friends = defaultdict(set)
for a, b in friendShips:
	friends[a].add(b)
	friends[b].add(a)

# Generate Euler Walk 
euler = []
eulerIndexes = defaultdict(list)
nodeHeight = {}
def dfs(atNode, fromNode = -1, height = 0):
	eulerIndexes[atNode].append(len(euler))
	nodeHeight[atNode] = height
	subNodes = friends[atNode]
	if len(subNodes) == 1 and list(subNodes)[0] == fromNode:
		euler.append((atNode, height))
		return
	for newNode in subNodes:
		if newNode == fromNode:
			continue
		euler.append((atNode, height))
		dfs(newNode, atNode, height + 1)
	euler.append((atNode, height))
dfs(1)
# Construct Sparse Table for euler
eulerST = SparseTable(list(map(lambda x: x[1], euler)))

def findFriendDistance(a, b):
	firstEulerExplored, secondEulerExplored = min(a, b, key=lambda x:eulerIndexes[x][0]), max(a, b, key=lambda x:eulerIndexes[x][0])
	firstEulerExploredIndex, secondEulerExploredIndex = map(lambda x: eulerIndexes[x][0], (firstEulerExplored, secondEulerExplored))
	# does the euler walk go past a, back up through a (second time) then go to point b
	if len(eulerIndexes[firstEulerExplored]) == 2 and eulerIndexes[firstEulerExplored][1] < secondEulerExploredIndex:
		firstEulerExploredIndex = eulerIndexes[firstEulerExplored][1]

	# TODO Implement Sparse Table for Minimum Range Query
	# LCAvertex, LCAheight = min(euler[firstEulerExploredIndex:secondEulerExploredIndex + 1], key=lambda x: x[1])
	LCAheight = eulerST.min(firstEulerExploredIndex, secondEulerExploredIndex)
	# find least common ancestor of a and b
	# find distance between a and LCA
	aHeight = nodeHeight[a]
	aLCADist = aHeight - LCAheight
	# find distance between b and LCA
	bHeight = nodeHeight[b]
	bLCADist = bHeight - LCAheight
	return aLCADist + bLCADist

# solve the opposite problem
# friends will be joined until tree
# unionfind to check if they are joined

uf = UnionFind(studentCount + 1)
out = []
for action, a, b in queries:
	if action == 1:
		out.append(-1 if not uf.isJoined(a, b) else findFriendDistance(a, b))
	elif action == 2:
		uf.join(a, b)
	else:
		raise Exception("Action number not valid")

print("\n".join(reversed(tuple(map(str, out)))))