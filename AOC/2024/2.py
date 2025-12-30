from typing import Counter


lines = open("2.in").readlines()

out = 0
for line in lines:
	line = line.strip()
	levels = list(map(int, line.split()))

	# determine if levels is safe

	# determine the direction
	x1 = levels[0] < levels[1]
	x2 = levels[1] < levels[2]
	x3 = levels[2] < levels[3]
	increasing = Counter([x1, x2, x3]).most_common(1)[0][0]

	dp = [1 for _ in range(len(levels))]
	for i in range(1, len(levels)): # right pointer
		for j in range(i - 1, -1, -1): # left pointer
			if 1 <= (levels[i] - levels[j] if increasing else levels[j] - levels[i]) <= 3:
				dp[i] = max(dp[i], dp[j] + 1)
				break
	out += len(levels) - max(dp) <= 1

print(out)