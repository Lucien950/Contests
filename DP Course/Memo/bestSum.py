bad = set()
dp = {}
def bestSum(targetSum: int, numbers: list[int])->list[int] or None:
	if targetSum == 0:
		return []
	if targetSum < 0 or targetSum in bad:
		return
	if targetSum in dp:
		return dp[targetSum]

	best = None
	for num in numbers:
		res = bestSum(targetSum - num, numbers)
		if res is not None:
			combination = res + [num]
			if best is None:
				best = combination
			elif len(combination) < len(best):
				best = combination

	if best is None:
		bad.add(targetSum)
	else:
		dp[targetSum] = best
	return best

print(bestSum(100, [1, 2, 5, 25]))