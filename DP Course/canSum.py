badTargetSums = set()

def canSum(targetSum: int, numbers: list[int])->bool:
	if targetSum == 0:
		return True
	if targetSum < 0:
		return False
	if targetSum in badTargetSums:
		return False

	for i in numbers:
		if canSum(targetSum - i, numbers):
			return True

	badTargetSums.add(targetSum)
	return False

print(canSum(301, [7, 14]))