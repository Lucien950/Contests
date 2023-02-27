from itertools import combinations
cases = int(input())
for case in range(cases):
	points = [tuple(map(int, input().split())) for _ in range(4)][1:]
	count = 0

	# print(points)
	for p1, p2 in combinations(points, 2):
		count += 1 if p1[0] == p2[0] or p1[1] == p2[1] else 0
	print("YES" if count <= 1 else "NO")