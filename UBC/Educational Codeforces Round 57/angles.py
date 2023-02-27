def solve():
	angle = int(input())
	if angle == 0:
		return 3
	target = angle/180
	n=3
	t=1
	while t/n != target:
		if t/n < target:
			if t >= n-2: n += 1
			else: t += 1
		elif t/n > target: n += 1
	return n
cases = int(input())
for case in range(cases):
	print(solve())