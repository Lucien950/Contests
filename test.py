import numpy as np

def done_or_not(board):
	def checkUnique(a):
		if len(a) == len(set(a)):
			return True
		else:
			return False

	boardN = np.array(board)

	# Check Rows and Columns
	for row in board:
		if not checkUnique(row):
			return 'Try again!'
	for i in range(9):
		if not checkUnique(boardN[:, i]):
			return 'Try again!'

	# Check Squares
	for rowNum in range(0, 9, 3):
		for colNum in range(0, 9, 3):
			square = np.reshape(boardN[rowNum:rowNum + 3, colNum:colNum + 3], 9)
			if not checkUnique(square):
				return 'Try again!'

	return 'Finished!'

print(done_or_not([[1, 3, 2, 5, 7, 9, 4, 6, 8]
                        ,[4, 9, 8, 2, 6, 1, 3, 7, 5]
                        ,[7, 5, 6, 3, 8, 4, 2, 1, 9]
                        ,[6, 4, 3, 1, 5, 8, 7, 9, 2]
                        ,[5, 2, 1, 7, 9, 3, 8, 4, 6]
                        ,[9, 8, 7, 4, 2, 6, 5, 3, 1]
                        ,[2, 1, 4, 9, 3, 5, 6, 8, 7]
                        ,[3, 6, 5, 8, 1, 7, 9, 2, 4]
                        ,[8, 7, 9, 6, 4, 2, 1, 5, 3]]))