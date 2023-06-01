s = input()
alpha = [0] * 26

toIndex = lambda x: ord(x) - 97
for c in s:
	cIndex = toIndex(c)
	if cIndex == 0: alpha[cIndex] = 1; continue
	alpha[cIndex] = max(alpha[cIndex], max(alpha[:cIndex]) + 1)
print(26-max(alpha))