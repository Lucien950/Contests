import statistics
totalFriends = int(input())

stringBorgor = input.split(" ")
burgerList = []
for i in stringBorgor:
	burgerList.append(int(i))

sortedBurgers = sorted(burgerList)
maxNum = sortedBurgers[len(sortedBurgers)-1]

chances = []

def solve():
	for c in range(1, maxNum+1):
		if c == burgerList[0]:
			chances.append(1.0)
			continue
		

	return statistics.mean(chances)


print(solve())