cases = int(input())
for case in range(cases):
	n = int(input())
	l = list(map(int, input().split()))
	print(" ".join(map(str, [n - i + 1 for i in l])))