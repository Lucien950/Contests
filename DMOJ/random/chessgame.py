inputList = """5 5
..*..
.....
.*.**
*..*.
.*.*.""".split("\n")
input = lambda: inputList.pop(0)

from itertools import islice
height, width = map(int, input().split())
board = [list(input()) for _ in range(height)]
used = [[False for _ in range(width)] for _ in range(height)]
out = 0

def check(iterator, flipCoords):
	global out, used
	# length is row/col
	for i, length in iterator:
		# get the index of the second instance of "*"
		try:
			firstPiece = length.index("*")
			secondPiece = length.index("*", firstPiece + 1)
		except:
			continue
		try:
			thirdPiece = length.index("*", secondPiece + 1)
		except:
			thirdPiece = None

		if thirdPiece:
			for j, item in enumerate(length):
				if item == ".":
					if flipCoords:
						add = not used[j][i]
						used[j][i] = True
					else:
						add = not used[i][j]
						used[i][j] = True
					if add: out += 1
		else:
			# check backwards and forwards
			def sliceEnum(Ilist, s, e):	return islice(enumerate(Ilist), s, e)

			for itt in (sliceEnum(length, 0, firstPiece), sliceEnum(length, secondPiece + 1, width)):
				for j, e in itt:
					if e == ".":
						if flipCoords:
							add = not used[j][i]
							used[j][i] = True
						else:
							add = not used[i][j]
							used[i][j] = True
						if add: out += 1

iterators = [
	(enumerate(board), False),
	(enumerate(zip(*board)), True),
]
# function
for iterator, flipCoords in iterators:
	check(iterator, flipCoords)

print(out)

# output
for i, row in enumerate(used):
	outstring = ""
	for j, e in enumerate(row):
		if board[i][j] == "*":
			outstring += "⬛"
		elif e:
			outstring += "✅"
		else:
			outstring += "❌"
	print(outstring)