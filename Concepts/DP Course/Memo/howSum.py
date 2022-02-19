# BIG INSIGHT OF THE PROBLEM
# Recursion with array adding
# Block off dead ends in DP
# once a non dead end is found, the answer is also found.

deadEnds = set()
def howSum(targetSum: int, numbers: list[int]):
	if targetSum == 0:
		return []
	if targetSum < 0:
		return
	if targetSum in deadEnds:
		return

	for num in numbers:
		remain = targetSum - num
		res = howSum(remain, numbers)
		if res is not None:
			res.append(num)
			# IMPORTANT
			# dp[targetSum] = res
			return res

	# IMPORTANT
	deadEnds.add(targetSum)

print(howSum(301, [7, 14]))