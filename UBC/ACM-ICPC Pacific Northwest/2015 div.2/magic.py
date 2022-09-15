from itertools import repeat


class Operation:
	def __init__(self, data) -> None:
		self.op = {
			"ADD": lambda x, y: x + y,
			"SUBTRACT": lambda x, y: x - y,
			"MULTIPLY": lambda x, y: x * y,
			"DIVIDE": lambda x, y: x / y
		}[data[0]]
		self.val = int(data[1])

operationCount = int(input())
operations = [Operation(input().split()) for _ in range(operationCount)]

nums = list(range(1, 101))
for operation in operations:
	nums = map(operation.op, nums, repeat(operation.val))
	nums = filter(lambda x: x >= 0 and round(x) == x, nums)

print(100-len(list(nums)))