stoneCount = int(input())
heights = list(map(int, input().split()))

dp = [float('inf') for _ in range(stoneCount)]
dp[0] = 0

for stoneIndex in range(stoneCount):
	for jumpSize in range(1, 3):
		landStone = stoneIndex + jumpSize
		if landStone >= stoneCount:
			continue
		cost = abs(heights[landStone] - heights[stoneIndex])
		dp[landStone] = min(dp[landStone], cost + dp[stoneIndex])

print(dp[-1])