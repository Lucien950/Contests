from typing import List

class Solution:
	def rotate(self, matrix: List[List[int]]) -> None:
		"""
		Do not return anything, modify matrix in-place instead.
		"""
		print([[i[k] for i in matrix][::-1] for k in range(len(matrix))])

s = Solution()
s.rotate([[1,2,3],[4,5,6],[7,8,9]])