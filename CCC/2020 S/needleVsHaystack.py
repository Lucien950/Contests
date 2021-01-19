from itertools import permutations
needle = input()
hay = input()

yee = permutations(needle)#Needle abc produces ['abc', 'acb', 'bac', 'bca', 'cba', 'cab']

permutes = []
for i in yee:
	toAdd = ''.join(i)
	if toAdd not in permutes:
		permutes.append(toAdd)
loopPermutes = permutes.copy()
original = len(permutes)

for i in loopPermutes:
	if i in hay:
		permutes.remove(i)

print(original-len(permutes))
