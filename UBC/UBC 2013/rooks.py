board = [[False for _ in range(8)] for _ in range(8)]
def solve(currentBounds: list[tuple[int, ...]]) -> bool:
	global board
	if len(currentBounds) == 0: return True
	minX, minY, maxX, maxY = currentBounds[0]
	for y in range(minY - 1, maxY):
		for x in range(minX - 1, maxX):
			if board[y][x]: continue
			if any(board[y]) or any([row[x] for row in board]): continue
			board[y][x] = True
			if solve(currentBounds[1:]): return True
			board[y][x] = False
	return False

while True:
	n = int(input())
	if n == 0: break
	bounds = [tuple(map(int, input().split())) for _ in range(n)]
	board = [[False for _ in range(8)] for _ in range(8)]
	solvable = solve(bounds)
	if solvable:
		locations = [(x,y) if element else None for y in range(len(board)) for x, element in enumerate(board[y])]
		locations = filter(lambda x: x != None, locations)

		# just for testing
		# assert(all([row.count(True) == 1 for row in board])) # assert that each row has only one rook
		# assert(all([[row[col] for row in board].count(True) == 1 for col in range(8)])) # assert that each col has only one rook

		# REAL OUTPUT
		print("\n".join(map(lambda l: f"{l[0]} {l[1]}" if l != None else "",locations)))
		# TESTING OUTPUT
		# print("\n".join(["".join(["O" if isRook else "_"for isRook in row]) for row in board]))
	else:
		print("IMPOSSIBLE") 