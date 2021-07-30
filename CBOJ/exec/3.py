def tenMods(power):
	a = [3, 2, 6, 4, 5, 1]
	return a[power%6 - 1]

def decomposeMod(n):
	letters = str(n)
	power = len(letters)-1
	final = 0
	for i in letters:
		bits = int(i) % 7
		bits *= tenMods(power)
		final += bits
		power -= 1
	return final % 7


N, Q = map(int, input().split())
arr = list(map(int, input().split()))
modArr = {i:decomposeMod(i) for i in arr}
queries = []
for i in range(Q):
	queries.append(tuple(map(int, input().split())))

for l,r in queries:
	final = 0
	power = len("".join(map(str, arr[l-1:r])))
	for i in arr[l-1:r]:
		power -= len(str(i))
		bits = modArr[i]
		bits *= tenMods(power)
		bits = decomposeMod(bits)
		final += bits
	print(decomposeMod(final))