cases = int(input())
for case in range(cases):
	s, t = [input() for _ in range(2)]
	print("".join(sorted(s+t)[:len(s)]))