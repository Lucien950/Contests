from collections import defaultdict
from typing import List


class Solution:
	def findAllPeople(self, n: int, meetings: List[List[int]], firstPerson: int) -> List[int]:
		earliest_visited: defaultdict[int, int | float] = defaultdict(lambda: float('inf'))
		adj: defaultdict[int, list[tuple[int, int]]] = defaultdict(list)
		for x, y, t in meetings:
			adj[x].append((y, t))
			adj[y].append((x, t))

		explored: set[int] = {0, firstPerson} 
		explore: set[int] = {0, firstPerson}
		earliest_visited[firstPerson] = 0
		earliest_visited[0] = 0
		while explore:
			at= explore.pop()
			for next, time in adj[at]:
				if time >= earliest_visited[next]:
					continue
				if  time < earliest_visited[at]:
					continue
				earliest_visited[next] = time
				explore.add(next)
				explored.add(next)
		return list(explored)

s = Solution()
print(s.findAllPeople(6, [[1,2,5],[2,3,8],[1,5,10]], 1))