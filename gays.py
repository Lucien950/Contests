import itertools as itt
from inspect import getsource
getName = lambda l: getsource(l).split('=')[0].strip()


p = lambda a, b:a+b
s = lambda a, b:a - b
m = lambda a, b:a * b
d = lambda a, b:a / b
e = lambda a, b:a ** b
r = lambda a, b:a ** (1/float(b))
opListFile = open('op.txt', 'a')

functions = {p, s, m, d, e, r}
commutables = {p, m}
convert = {
	'p':'+',
	's':'-',
	'm':'*',
	'd':'/',
	'e':'^',
	'r':'^1/',
}

# class Tree:
# 	def __init__(self, l, r, op):
# 		self.children = {l,r}
# 		self.op = op
# 	def __eq__(self, other):
# 		if not isinstance(other, Tree):
# 			return False
# 		return self.children == other.children and self.op == other.op
# 	def __hash__(self):
# 		return hash(0)
# class MatterTree:
# 	def __init__(self, l, r, op):
# 		self.children = [l, r]
# 		self.op = op
# 	def __eq__(self, other):
# 		if not isinstance(other, Tree):
# 			return False
# 		return list(self.children) == list(other.children) and self.op == other.op
# 	def __hash__(self):
# 		return hash(0)
#
# takenTrees = []

for a, b, c, d in [map(int, i) for i in itt.permutations('1234', 4)]:
	# Runs for each combination of numbers
	for op1, op2, op3 in [i for i in itt.permutations(functions,3)]:
		#2 by 2 grouping, ie (f(a, b), f(c, d))
		if op1(op2(a, b), op3(c, d)) == 2:
			opListFile.write('('+str(a)+convert[getName(op2)]+str(b)+')' + convert[getName(op1)] + '(' + str(c) + convert[getName(op3)] + str(d)+')')
			opListFile.write("\n")
		
		#2, 1, 1 grouping, ie f(f(f(a, b), c), d)
		if op1(op2(op3(a, b), c), d) == 2:
			opListFile.write('((' + str(a) + convert[getName(op3)] + str(b) + ')' + convert[getName(op2)] + str(c) + ')' + convert[getName(op1)] + str(d))
			opListFile.write("\n")