def gridTraveller(x, y):
	table = [[0 for i in range(x + 1)] for j in range(y + 1)]
	table[1][1] = 1

	for n in range(1, y + 1):
		for m in range(1, x + 1):
			val = table[n][m]
			if n < y:
				table[n + 1][m] += val
			if m < x:
				table[n][m+1] += val
	print("\n".join(map(str, table)))
	return table[-1][-1]

print(gridTraveller(18, 18))