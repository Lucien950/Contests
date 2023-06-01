from typing import List

class Solution:
	def search(self, nums: List[int], target: int) -> int:
		# left bisection
		# [0,1, 2, 3, 4, 4, 4, 5]
		l, r = 0, len(nums)
		while l < r:
			mid = (l + r)//2

			if nums[mid] == target: return mid

			if nums[mid] < target:
				l = mid + 1
			else:
				r = mid
		return -1


Solution().search([-1,0,3,5,9,12], 8)