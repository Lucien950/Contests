from collections import deque
colCount = int(input())
board = [list(map(int, input().split())) for _ in range(2)]

total = 0

explored = [[False for _ in range(colCount)] for _ in range(2)]
for y in range(2):
	for x in range(colCount):
		if explored[y][x] or board[y][x] == 0: continue

		explored[y][x] = True

		# BFS
		toExplore = deque([(x, y)])
		while toExplore:
			atX, atY = toExplore.popleft()

			neighbours = 0
			for dx, dy in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
				newX, newY = atX + dx, atY + dy
				if not (0 <= newX < colCount and 0 <= newY < 2): continue
				# if odd column, reject up and down movement
				if dy != 0 and atX % 2 != 0: continue
				if board[newY][newX] == 0: continue

				neighbours += 1

				if explored[newY][newX]: continue
				explored[newY][newX] = True
				toExplore.append((newX, newY))
			total += 3 - neighbours

print(total)