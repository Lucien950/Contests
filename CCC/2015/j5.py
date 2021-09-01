# import sys
# input = sys.stdin.readline

pieCount = int(input())
peopleCount = int(input())

# dp[at][remainPie] and its 1 indexed (oops)
dp = [ [0] * (pieCount + 1) for i in range(peopleCount) ]
def getWays(lastGive, at, remainPie):
	# if we are at the last person
	if at == peopleCount - 1:
		return 1

	# if dp has already solved it
	if dp[at][remainPie] != 0:
		return dp[at][remainPie]

	# which person are we distributing to
	ways = 0
	give = lastGive
	while give * (peopleCount - at) <= remainPie:
		add = getWays(give, at + 1, remainPie - give)
		ways += add
		dp[at + 1][remainPie - give] += add

		give += 1

	return ways

print(getWays(1, 0, pieCount))
pass