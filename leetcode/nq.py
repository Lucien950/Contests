from typing import List

class Solution:
	def solve(self, row: int):
		if row == self.n:
			# update solution
			clean = ["".join(["Q" if element else "." for element in r]) for r in self.board]
			self.ans.append(clean)
			return
		for x in range(self.n):
			# check if x is in occupied col
			if x in self.occupiedCol: continue
			# check if x, row (y) is in an occupied diag
			if x + row in self.posdiag or x - row in self.negdiag: continue

			self.occupiedCol.add(x)
			self.posdiag.add(x + row)
			self.negdiag.add(x - row)
			self.board[row][x] = True
			
			self.solve(row + 1)

			self.occupiedCol.remove(x)
			self.posdiag.remove(x + row)
			self.negdiag.remove(x - row)
			self.board[row][x] = False

	def solveNQueens(self, n: int) -> List[List[str]]:
		self.occupiedCol = set()
		self.posdiag = set()
		self.negdiag = set()
		self.ans = []
		self.board = [[False for _ in range(n)] for _ in range(n)]
		self.n = n
		self.solve(0)

		return self.ans
	
sol = Solution().solveNQueens(4)
print(sol)