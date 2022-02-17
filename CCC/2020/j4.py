def solve():
	long = input()
	cycle = input()

	cycles = []
	for i in range(len(cycle)):
		cycles.append(cycle)
		cycle = cycle[1:] + cycle[0]

	for start in range(len(long)-len(cycle) + 1):
		end = start + len(cycle)
		if long[start:end] in cycles:
			print("yes")
			return
	print("no")

solve()