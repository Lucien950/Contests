from collections import Counter
import sys
from typing import Literal, Self
input = sys.stdin.readline

class Node:
	children = {}
	def add(self, c: str) -> None:
		self.children[c] = Node()
	def remove(self, c: str)-> None:
		del self.children[c]
	def getChild(self, c: str) -> Self:
		if c not in self.children.keys(): raise Exception("Child not in Children")
		return self.children[c]
	def childrenCount(self):
		return len(self.children)

class Trie:
	root = Node()
	def add(self, val):
		node = self.root
		
		for s in bin(val)[2:]:
			node.add(s)
			node = node.getChild(s)
	def remove(self, left):
		node = self.root
		if node.childrenCount == 0: return True
		child = node.getChild(bin(left)[2:][0])
		shouldRemoveChild = child.remove(left ^ (1 << (left - 1)))
		if shouldRemoveChild:
			node.remove(bin(left)[2:][0])
		return node.childrenCount == 0
		
	def query(self):
		pass

def rightIndexVal(num, i) -> Literal[0, 1]:
	return (num & 2**i) >> i

queryCount = int(input())
queries = [input().rstrip().split() for _ in range(queryCount)]

multiSet = Counter()
t = Trie()
for query in queries:
	command, queryVal = query
	queryVal = int(queryVal)
	if command == "+":
		if multiSet[queryVal] == 0:
			t.add(queryVal)
		multiSet[queryVal] += 1
	elif command == "-":
		multiSet[queryVal] -= 1
		if multiSet[queryVal] == 0:
			t.remove(queryVal)
	elif command == "?":
		# best = (2**32-1) ^ queryVal
		pass

print("done")