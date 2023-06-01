from typing import List

class Solution:
	def findMin(self, nums: List[int]) -> int:
		l, r = 0, len(nums) - 1
		while not (r - l <= 1):
			mid = (l + r)//2
			if nums[mid] < nums[r]:
				r = mid
			else:
				l = mid
		return min(nums[l], nums[r])

print(Solution().findMin([3,4,5,1,2]))
print(Solution().findMin([4,5,6,7,0,1,2]))
print(Solution().findMin([11,13,15,17]))