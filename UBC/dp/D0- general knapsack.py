itemCount, maxWeight = map(int, input().split())
items = [tuple(map(int, input().split())) for _ in range(itemCount)]

dp = [0 for _ in range(maxWeight + 1)]
for atWeight in range(maxWeight + 1):
	for weight, value in items:
		endWeight = atWeight + weight
		if endWeight >= maxWeight + 1: continue
		dp[endWeight] = max(dp[endWeight], dp[atWeight] + value)
print(max(dp))