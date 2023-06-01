from collections import defaultdict
from typing import List
class Solution:
	def noCycles(self, course: int):
		if course in self.visiting: return False
		if course in self.confirmed: return True
		if course not in self.adj: return True
		self.visiting.add(course)
		for nextNode in self.adj[course]:
			if not self.noCycles(nextNode): return False
		self.visiting.remove(course)
		self.confirmed.add(course)
		return True

	def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
		# Globals
		self.confirmed = set()
		self.visiting = set()
		self.adj = defaultdict(list)
		self.numCourses = numCourses

		for a, b in prerequisites:
			self.adj[b].append(a)
			if a == b: return False
		for course in self.adj.keys():
			if not self.noCycles(course):
				return False
		return True