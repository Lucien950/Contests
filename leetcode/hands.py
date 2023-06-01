from typing import List

from collections import Counter
class Solution:
	def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
		if len(hand) % groupSize != 0: return False
		handCounter = Counter(hand)

		for start in sorted(handCounter.keys()):
			while handCounter[start] > 0:
				for i in range(start, start + groupSize):
					if handCounter[i] == 0: return False
					handCounter[i] -= 1
		return True


print(Solution().isNStraightHand([1,2,3,6,2,3,4,7,8], 3))