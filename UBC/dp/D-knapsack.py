# 0/1 knapsack
itemCount, maxWeight = map(int, input().split())
items = [tuple(map(int, input().split())) for _ in range(itemCount)]

dp = [[0 for _ in range(maxWeight + 1)] for _ in range(itemCount + 1)]
for itemIndex in range(itemCount):
	itemWeight, itemValue = items[itemIndex]
	for weight in range(maxWeight + 1):
		dp[itemIndex][weight] = max(
			dp[itemIndex - 1][weight],
			(dp[itemIndex - 1][weight - itemWeight] + itemValue if weight - itemWeight >= 0 else -1)
		)
print(dp[-2][-1])