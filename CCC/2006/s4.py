while True:
	n = int(input())
	if n == 0:
		break

	chart = []
	for i in range(n):
		chart.append(list(map(int, input().split())))

	