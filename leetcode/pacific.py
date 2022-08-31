from typing import List
from itertools import repeat

class Solution:
	height, width = -1, 1
	heights = []

	def floodFill(self, toExplore, l):
		while toExplore:
			x, y = toExplore.pop()
			l[y][x] = True
			for deltaY, deltaX in ((1, 0), (0, 1), (-1, 0), (0, -1)):
				inBounds = 0 <= x + deltaX < self.width and 0 <= y + deltaY < self.height
				if inBounds and self.heights[y + deltaY][x + deltaX] >= self.heights[y][x]:
					if not l[y + deltaY][x + deltaX]:
						toExplore.add((x + deltaX, y + deltaY))

	def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
		self.height, self.width = len(heights), len(heights[0])
		self.heights = heights

		p = [[False for _ in range(self.width)] for _ in range(self.height)]
		a = [[False for _ in range(self.width)] for _ in range(self.height)]
		# flood fill p
		toExplore = {(0, 0)}
		toExplore = toExplore.union(set(zip(repeat(0), range(1, self.height))))
		toExplore = toExplore.union(set(zip(range(1, self.width), repeat(0))))
		self.floodFill(toExplore, p)
		# flood fill a
		toExplore = {(self.width-1, self.height-1)}
		toExplore = toExplore.union(set(zip(repeat(self.width - 1), range(self.height))))
		toExplore = toExplore.union(set(zip(range(self.width), repeat(self.height - 1))))
		self.floodFill(toExplore, a)
		
		# output
		out = []
		for rowNum in range(self.height):
			for colNum in range(self.width):
				if p[rowNum][colNum] and a[rowNum][colNum]:
					out.append([rowNum, colNum])
		return out

s = Solution()
s.pacificAtlantic([[1,1],[1,1],[1,1]])