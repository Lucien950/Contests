from collections import deque
from typing import List

class Solution:
	def numIslands(self, grid: List[List[str]]) -> int:
		h, w = len(grid), len(grid[0])
		explored = [[False for _ in range(w)] for _ in range(h)]

		islands = 0
		for i in range(h):
			for j in range(w):
				if grid[i][j] == "0": continue
				
				if explored[i][j]: continue

				islands += 1
				toexplore = deque()
				toexplore.append((j, i))
				while toexplore:
					x, y = toexplore.popleft()
					explored[y][x] = True
					for dx, dy in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
						newX, newY = x + dx, y + dy
						if not (0 <= newX < w and 0 <= newY < h): continue
						if grid[newY][newX] == "0" : continue
						if explored[newY][newX]: continue
						explored[newY][newX] = True
						toexplore.append((newX, newY))
		return islands

Solution().numIslands([["1","0","1","1","0","1","1"]])