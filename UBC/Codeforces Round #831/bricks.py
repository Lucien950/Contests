def solve():
	brickCount = int(input())
	bricks = sorted(set(map(int, input().split())))
	if len(bricks) == 1: return 0
	if len(bricks) == 2: return (bricks[1] - bricks[0]) * 2
	return bricks[-1] - bricks[0] + max(bricks[-1] - bricks[-2], bricks[1] - bricks[0])


cases = int(input())
for case in range(cases):
	print(solve())