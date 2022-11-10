sections = int(input())
paints = int(input())

maxThick = 1
maxI = -1
rockPaint = [1 for _ in range(sections + 1)]
for paint in range(paints):
	start, end = map(int, input().split())
	for section in range(start, end + 1):
		rockPaint[section] += 1
		if rockPaint[section] > maxThick:
			maxThick = rockPaint[section]
			maxI = section
		elif rockPaint[section] == maxThick:
			maxI = min(maxI, section)
print(maxI)