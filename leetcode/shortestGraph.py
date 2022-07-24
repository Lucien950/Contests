from collections import deque
from typing import List
class Solution:
	explored = []
	graph = []
	nodeCount = 0
	def dfs(self, at, depth = 0):
		self.explored[at] = True

		retVal = depth
		for nextNode in self.graph[at]:
			if not self.explored[nextNode]:
				self.dfs(nextNode, depth + 1)
				
		return retVal
	
	def shortestPathLength(self, graph: List[List[int]]) -> int:
		self.nodeCount = len(graph)
		self.graph = graph
		self.explored = [False for _ in range(self.nodeCount)]
		return self.dfs(0)
# Test
graph = [[1,2,3],[0],[0],[0]]
print(Solution().shortestPathLength(graph))