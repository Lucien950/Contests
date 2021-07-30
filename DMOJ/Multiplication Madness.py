taskCount = int(input())
MOD = 10**9+7

# factorialList[i] = i! % MOD
factorialList = [1, 1]
for i in range(2, 10**6 + 1):
	new = i * factorialList[i - 1]
	factorialList.append(new % MOD)

def multiplyList(a, b):
	if a == 0:
		return 0
	return (factorialList[b] * pow(factorialList[a-1], -1, MOD))% MOD

for i in range(taskCount):
	a, b = map(int, input().split())
	print(multiplyList(a, b))