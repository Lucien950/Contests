from typing import List

class Solution:
	@staticmethod
	def threeSum(nums: List[int]) -> List[List[int]]:
		nums.sort()
		sols = []
		for i, target in enumerate(map(lambda x: -x, nums)):
			if i > 0 and target == nums[i - 1]: continue
			l, r= i + 1, len(nums) - 1
			while l < r:
				pointerSum = nums[l] + nums[r]
				if pointerSum == target:
					sol = sorted([nums[l], nums[r], nums[i]])
					if sol not in sols: sols.append(sol)
					l += 1
				if pointerSum > target: r -= 1
				if pointerSum < target: l += 1
		return sols