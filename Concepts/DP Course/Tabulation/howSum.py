def howSum(targetSum: int, numbers: list[int]) -> list[int]:
	dp: list[list[int]] = [[-1]] * (targetSum + 1)
	dp[0] = []
	for start in range(targetSum):
		if dp[start] == [-1]:
			continue
		for num in numbers:
			newReachable = start + num

			# little cheeky optimization here to make it bestSum
			outOfBounds = newReachable > targetSum
			filled = dp[newReachable] != [-1] if not outOfBounds else None
			otherShorterThanThis = len(dp[newReachable]) < len(dp[start]) + 1 if not outOfBounds else None
			if outOfBounds or filled and otherShorterThanThis:
				continue

			dp[newReachable] = dp[start] + [num]

	# print(dp)
	return dp[targetSum] if dp[targetSum] != [-1] else []

print(howSum(7, [3, 4, 5]))
print(howSum(301, [7, 14]))
print(howSum(8, [2, 3, 5]))
print(howSum(100, [1, 2, 5, 25]))