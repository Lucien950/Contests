from typing import List


class Solution:
	def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
		u, d = 0, len(matrix)
		while d - u > 1:
			mid = (u + d)//2
			if matrix[mid][0] == target:
				return True
			if matrix[mid][0] < target:
				u = mid
			else:
				d = mid
		
		subL = matrix[u]
		l, r = 0, len(subL)
		while l < r:
			mid = (l + r)//2
			if subL[mid] == target:
				return True
			
			if subL[mid] < target:
				l = mid + 1
			else:
				r = mid
		return False

s = Solution()
print(s.searchMatrix([[1,3,5,7],[10,11,16,20],[23,30,34,60]], 16))