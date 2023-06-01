from typing import List
from math import ceil

from random import randint

class Solution:
	def needTurns(self, piles, k) -> int:
		return sum([ceil(p/k) for p in piles])
	def minEatingSpeed(self, piles: List[int], h: int):
		minK, maxK = 1, max(piles)
		while minK <= maxK:
			midK = (minK + maxK) // 2
			requiredTurns = self.needTurns(piles, midK)
			if requiredTurns <= h:
				maxK = midK - 1
			else:
				minK = midK + 1
		return minK

# expects 142857143
print(Solution().minEatingSpeed([randint(1, 30) for _ in range(9999)], 10))