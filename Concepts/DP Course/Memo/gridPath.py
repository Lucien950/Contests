dp = {}
def gridTravel(height, width):
	key = ",".join(map(str, [height, width]))
	if key in dp:
		return dp[key]
	if height == 1 and width == 1:
		return 1
	if height == 0 or width == 0:
		return 0

	dp[key] = gridTravel(height - 1, width) + gridTravel(height, width - 1)
	return dp[key]

print(gridTravel(18, 18))