from typing import List
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1
        totalSum = sum(nums)
        bestSum = totalSum
        while l < r:
            bestSum = max(bestSum, totalSum)
            dropLCost, dropRCost = -nums[l], -nums[r]
            if dropLCost < dropRCost:
                r -= 1
                totalSum += dropRCost
            else:
                l += 1
                totalSum += dropLCost
        return bestSum
    
Solution().maxSubArray([-2,1,-3,4,-1,2,1,-5,4])