cases = int(input())
for case in range(cases):
	length = int(input())
	a = list(map(int, input().split()))
	d = [a[0]]
	kill = False
	for i, e in list(enumerate(a))[1:]:
		if d[i-1] >= e and e != 0:
			kill = True
			break
		d.append(d[i-1] + e)
	if kill:
		print(-1)
	else:
		print(" ".join(map(str, d)))