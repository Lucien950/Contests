inputCase = """7
47 12 12 3 9 9 3""".splitlines()
def input():
	global inputCase
	x = inputCase.pop(0)
	print(x)
	return x

ballCount = int(input())
balls = list(map(int, input().split()))

# make prefix sum array of balls
# sumRange(start, end) to get sum of all balls, inclusive of start and end
sumArr = [0]
for i in range(len(balls)):
	sumArr.append(sumArr[-1] + balls[i])

def sumRange(start, end): return sumArr[end + 1] - sumArr[start]

# x coordinates represent the left bound, right bound is y
dp = [[-1 for _ in range(ballCount)] for _ in range(ballCount)]
res = 0
for i in range(ballCount):
	dp[i][i] = sumRange(i, i)
	res = max(res, dp[i][i])

for q in range(1,ballCount):
	for left, right in zip(range(ballCount), range(q, ballCount)):
		print("hello")

[print(row) for row in dp]
print(res)