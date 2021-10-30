def displayBoard(board):
	convert = {-1: '□', 0: '.', 1: '■'}
	print("---------------\n" + "\n".join([" ".join([convert[element] for element in row]) for row in board]) + "\n---------------")

shit = input().split()
config = shit[0]
moveCount = int(shit[1])
rest = shit[2:]
# split rest into groups of two
moves = [[int(rest[i]) for i in range(2*j, 2*j+2)] for j in range(moveCount)]

# Board setup
board = []
if config == 'a':
	a = [[0 for i in range(8)] for j in range(8)]
	a[3][3] = 1
	a[3][4] = -1
	a[4][3] = -1
	a[4][4] = 1
	board = a
elif config == 'b':
	b = [[0 for i in range(8)] for j in range(8)]
	for row in range(8):
		for col in range(8):
			# Set up B
			if row == col:
				b[row][col] = 1
			elif row == 7-col:
				b[row][col] = -1
	board = b
elif config == 'c':
	c = [[0 for i in range(8)] for j in range(8)]
	for row in range(8):
		for col in range(8):        
			# Set up C
			if col == 2 or col == 3:
				c[row][col] = 1
			elif col == 4 or col == 5:
				c[row][col] = -1
	board = c
else:
	raise ValueError('Invalid config')


blackMove = True

# while True:
	# print(f"{'Black' if blackMove else 'White'} to move, enter (row, col)")
	# _row, _col = map(int, input().split())
def fill(location, piece):
	row, col = location
	filledLocations = []
	# fill row
	if col != 0:
		leftPieces = board[row][:col]
		# find rightmost index of True in leftHasPiece
		leftIndex = -1
		for i, val in list(enumerate(leftPieces))[::-1]:
			if val == piece:
				leftIndex = i
				break
			elif val == 0:
				break
		if leftIndex != -1:
			# fill left
			for i in range(leftIndex, col):
				board[row][i] = piece
				filledLocations.append((row, i))
	
	rightPieces = board[row][col+1:]
	rightIndex = -1
	for i, val in list(enumerate(rightPieces)):
		if val == piece:
			rightIndex = i + col + 1
			break
		elif val == 0:
			break
	# fill right
	if rightIndex != -1:
		for i in range(col+1, rightIndex):
			board[row][i] = piece
			filledLocations.append((row, i))
	
	# fill col
	if row != 0:
		upPieces = [i[col] for i in board[:row]]
		upIndex = -1
		for i, val in list(enumerate(upPieces))[::-1]:
			if val == piece:
				upIndex = i
				break
			elif val == 0:
				break
		# fill up
		if upIndex != -1:
			for i in range(upIndex, row):
				board[i][col] = piece
				filledLocations.append((i, col))
	
	downPieces = [i[col] for i in board[row+1:]]
	downIndex = -1
	for i, val in list(enumerate(downPieces)):
		if val == piece:
			downIndex = i + row + 1
			break
		elif val == 0:
			break        
	# fill down
	if downIndex != -1:
		for i in range(row+1, downIndex):
			board[i][col] = piece
			filledLocations.append((i, col))
	
	for location in filledLocations:
		fill(location, piece)

for moveNumber,(_row, _col) in enumerate(moves):
	row = _row - 1
	col = _col - 1

	piece = -1 if blackMove else 1
	board[row][col] = piece
	fill((row, col), piece)
	displayBoard(board)
	blackMove = not blackMove

blackPieces = sum([i.count(-1) for i in board])
whitePieces = sum([i.count(1) for i in board])
print(blackPieces, whitePieces)