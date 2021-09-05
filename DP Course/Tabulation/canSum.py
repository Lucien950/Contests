def canSum(targetSum: int, numbers: list[int]):
	dp = [False] * (targetSum + 1)
	dp[0] = True
	for starting in range(targetSum):
		if not dp[starting]:
			continue
		for number in numbers:
			newReachable = starting + number
			if newReachable > targetSum:
				continue
			dp[newReachable] = True
	return dp[targetSum]

print(canSum(7, [3, 4, 5]))
print(canSum(301, [7, 14]))
