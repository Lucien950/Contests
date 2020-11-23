from itertools import accumulate

houseCount, toRake = map(int, input().split(" "))
moneyList = map(int, input().split(" "))

prefixList = list(accumulate(moneyList))
prefixList.insert(0, 0)

maxCash = 0

for first, last in enumerate(range(toRake, houseCount + 1)):
	toProfit = prefixList[last] - prefixList[first]
	maxCash = max(maxCash, toProfit)

print(maxCash)