class Solution:
	def isSafe(self, x, y):
		# -x, +y -> +x, -y
		for diagVal in range(-min(x, self.n - 1 - y), min(self.n - 1 - x, y) + 1):
			if self.board[y - diagVal][x + diagVal] == "Q": return False
		# top left to bottom right
		for diagVal in range(-min(x, y), min(self.n - x, self.n - y)):
			if self.board[y + diagVal][x + diagVal] == "Q": return False
		return True
	
	def solve(self, y):
		if y == self.n:
			self.ans.append(["".join(row) for row in self.board])
			return
		
		for x in range(self.n):
			xOccupied = x in self.occupiedCols
			posDiagOccupied, negDiagOccupied = x + y in self.posdiag, x - y in self.negdiag
			if not (xOccupied or posDiagOccupied or negDiagOccupied):
				self.board[y][x] = "Q"
				self.occupiedCols.add(x)
				self.posdiag.add(x+y)
				self.negdiag.add(x-y)

				# search
				self.solve(y + 1)

				# backtrack
				self.occupiedCols.remove(x)
				self.posdiag.remove(x+y)
				self.negdiag.remove(x-y)
				self.board[y][x] = "."

	def solveNQueens(self, n: int) -> list[list[str]]:
		self.board = [["."] * n for _ in range(n)]
		self.n = n
		self.ans = []

		self.posdiag = set()
		self.negdiag = set()
		self.occupiedCols = set()
		self.solve(0)
		return self.ans


from copy import deepcopy
class Solution1:
	n = None
	solutions = []
	explored = set()
	def getNumericalPosition(self, x, y): return self.n * y + x
	def sortTuple(self, t): return tuple(sorted(list(t)))

	def placeNext(self, board, validSpaces, placesLeft, exploredRepr = ()) -> int:
		if exploredRepr in self.explored: return
		if placesLeft == 0:
			sol = ["".join(row) for row in board]
			if sol not in self.solutions: self.solutions.append(sol)
			return
		
		for y in range(self.n):
			for x in range(self.n):
				if validSpaces[y][x] != True: continue
				
				self.explored.add(exploredRepr)

				newBoard = deepcopy(board)
				newBoard[y][x] = "Q"
				
				# clear valid spots
				newValidSpaces = deepcopy(validSpaces)
				for temp_x in range(self.n): newValidSpaces[y][temp_x] = False
				for temp_y in range(self.n): newValidSpaces[temp_y][x] = False

				# -x, +y -> +x, -y
				for diagVal in range(-min(x, self.n - 1 - y), min(self.n - 1 - x, y) + 1):
					newValidSpaces[y - diagVal][x + diagVal] = False

				# top left to bottom right
				for diagVal in range(-min(x, y), min(self.n - x, self.n - y)):
					newValidSpaces[y + diagVal][x + diagVal] = False
				
				self.placeNext(newBoard, newValidSpaces, placesLeft-1, self.sortTuple(exploredRepr + (self.getNumericalPosition(x, y), )))
	
	def solveNQueens(self, n: int) -> list[list[str]]:
		emptyBoard = [["." for _  in range(n)] for _ in range(n)]
		validBoard = [[True for _ in range(n)] for _ in range(n)]
		self.n = n
		self.solutions = []
		self.explored = set()
		
		self.placeNext(emptyBoard, validBoard, n)
		return self.solutions

sols = Solution().solveNQueens(4)
for sol in sorted(sols):
	print("\n".join(sol))
	print("===============")