from collections import defaultdict
import sys
input = sys.stdin.readline
# maximize sugar
firstSize = int(input())
first = [int(input()) for i in range(firstSize)]
secondSize = int(input())
second = [int(input()) for i in range(secondSize)]
second.sort()

dp=defaultdict(lambda:-1)
# solve(pos, 0, l, r)
# originalPieList[pos] + solve(pos+1, 0, l, r)
# addPieList[r]+solve(pos, 0, l, r-1)

# solve(pos+1, 1, l, r)
# solve(pos, 1, l+1, r)
def solve(pos: int, allowTake: bool, l:int, r:int):
	key = (pos, allowTake, l, r)
	if dp[key] != -1:
		return dp[key]
	# out of bounds
	if pos == firstSize:
		if l <= r:
			# take one from top if allowed
			if allowTake: dp[key] = second[r] + solve(pos, False, l, r - 1)
			# throw away one from bottom if not allowed
			else: dp[key] = solve(pos, True, l + 1, r)

		else: dp[key] = 0
		return dp[key]

	if allowTake:
		# the max between not taking or taking the current position pie
		# BEST PRACICE HERE IS TO STAY AND NOT TAKE HERE
		dp[key] = max(solve(pos, False, l, r), first[pos] + solve(pos + 1, False, l, r))
		#try taking the best one from M
		if l <= r: dp[key] = max(dp[key], second[r] + solve(pos, False, l, r-1))
	else:
		# go to next one regain taking privilegesd
		dp[key] = solve(pos + 1, True, l, r)
		# try ignoring the worst one and get taking privileges
		if l <= r: dp[key]=max(dp[key], solve(pos, True, l+1, r))
	return dp[key]

sys.setrecursionlimit(10000)
print(solve(0, True, 0, secondSize - 1))