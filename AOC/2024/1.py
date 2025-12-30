from collections import Counter

lines = open("1.in").readlines()

first, second = zip(*[line.strip().split() for line in lines])
first = [int(x) for x in first]
second = [int(x) for x in second]

f = sorted(first)
s = sorted(second)
s_c = Counter(s)

out  = 0
for x in f:
	out += x * s_c[x]
print(out)