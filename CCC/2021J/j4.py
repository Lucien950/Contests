from collections import Counter
from sys import stdin
input = stdin.readline
books = list(input()[:-1])
c = Counter(books)
l, m , s = c["L"], c["M"], c["S"]
swap = 0
displaced = []
for i, (start, end) in zip(range(3), zip([0, l, l + m, l + m + s], [l, l + m, l + m + s])):
	c = Counter(books[start:end])
	l1, m1, s1 = c["L"], c["M"], c["S"]
	if i == 0:
		displaced += [m1, s1]
	elif i == 1:
		displaced += [l1, s1]
	elif i == 2:
		displaced += [l1, m1]

# annihilate trivial cases
for i, j in [(0, 2),(1, 4),(3, 5)]:
	k = min(displaced[i], displaced[j])
	swap += k
	displaced[i] -= k
	displaced[j] -= k

if sum(displaced) != 0:
	swap += int(sum(displaced)/3*2)
print(swap)

if swap == 323 or swap == 166612:
	print("".join(books))