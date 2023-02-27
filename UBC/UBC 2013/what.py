e = list(map(lambda x: tuple(map(int, x.split())), """1 1
5 8
2 4
4 2
7 3
8 5
6 6
3 7""".split("\n")))
board = [[False for _ in range(8)] for _ in range(8)]
for x, y in e:
	board[y-1][x-1] = True
print("\n".join(["".join(["O" if isRook else "_"for isRook in row]) for row in board]))