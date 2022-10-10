days = int(input())
data = [list(map(int, input().split())) for _ in range(days)]
a, b, c = [i[0] for i in data], [i[1] for i in data], [i[2] for i in data]
activities = [a, b, c]

dp = [[0] * 3 for _ in range(days)]
dp[0] = list(map(lambda x: x[0], [a, b, c]))

for day in range(days-1):
	for atActivities in range(3): #a, b, c
		nextActivities = [0, 1, 2] #a, b, c
		nextActivities.remove(atActivities)
		for nextActivity in nextActivities:
			nextDp = dp[day][atActivities] + activities[nextActivity][day + 1]
			dp[day + 1][nextActivity] = max(dp[day + 1][nextActivity], nextDp)
print(max(dp[-1]))