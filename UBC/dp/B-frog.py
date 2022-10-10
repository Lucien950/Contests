stoneCount, longestJump = map(int, input().split())
heights = list(map(int, input().split()))

dp = [float('inf') for _ in range(stoneCount)]
dp[0] = 0

for stoneIndex in range(stoneCount):
	for jumpSize in range(1, longestJump + 1):
		landStone = stoneIndex + jumpSize
		if landStone >= stoneCount:
			continue
		cost = abs(heights[landStone] - heights[stoneIndex])
		dp[landStone] = min(dp[landStone], cost + dp[stoneIndex])

print(dp[-1])