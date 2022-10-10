# 0/1 knapsack
itemCount, maxWeight = map(int, input().split())
items = [tuple(map(int, input().split())) for _ in range(itemCount)]

dp = [[float('inf') for _ in range(10**5 + 1)] for _ in range(itemCount + 1)]
for itemIndex in range(itemCount):
	itemWeight, itemValue = items[itemIndex]
	dp[itemIndex][itemValue]= itemWeight
	
	# small optimization
	if itemIndex == 0: continue
	for value in range(10**5 + 1):
		dp[itemIndex][value] = min(dp[itemIndex][value], dp[itemIndex - 1][value])
		withPrevious = dp[itemIndex - 1][value - itemValue] if value - itemValue >= 0 else float('inf')
		if withPrevious != float('inf') and withPrevious + itemWeight <= maxWeight:
			dp[itemIndex][value] = min(dp[itemIndex][value], withPrevious + itemWeight)

for i in range(10**5 + 1):
	if dp[-2][-i] != float('inf'):
		print(10**5 + 1 - i)
		break