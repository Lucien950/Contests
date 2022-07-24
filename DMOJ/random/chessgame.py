inputList = """5 5
..*..
.....
.*.**
*..*.
.*.*.""".split("\n")
input = lambda: inputList.pop(0)

import sys
input = sys.stdin.readline

def replace(list, val, newval):
	for i in range(len(list)):
		if list[i] == val:
				list[i] = newval
	return list
height, width = map(int, input().split())
board = [replace(list(input()), ".", False) for _ in range(height)]
out = 0

for flipCoords in (False, True):
	if flipCoords: iterator = enumerate(zip(*board))
	else: iterator = enumerate(board)
	# length is row/col
	for i, length in iterator:
		# get the index of the second instance of "*"
		try:
			firstPiece = length.index("*")
			secondPiece = length.index("*", firstPiece + 1)
		except: continue

		try: thirdPiece = length.index("*", secondPiece + 1)
		except: thirdPiece = None

		if thirdPiece:
			for j in range(len(length)):
				item = length[j]
				if item == False:
					if flipCoords:
						board[j][i] = True
					else:
						board[i][j] = True
					out += 1
		else:
			end = height if flipCoords else width
			for itt in (range(0, firstPiece), range(secondPiece + 1, end)):
				for j in itt:
					e = length[j]
					if e == False:
						if flipCoords:
							board[j][i] = True
						else:
							board[i][j] = True
						out += 1
print(out)

# output
# for i, row in enumerate(used):
# 	outstring = ""
# 	for j, e in enumerate(row):
# 		if board[i][j] == "*":
# 			outstring += "⬛"
# 		elif e:
# 			outstring += "✅"
# 		else:
# 			outstring += "❌"
# 	print(outstring)