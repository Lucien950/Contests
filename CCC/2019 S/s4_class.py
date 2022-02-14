data ="""5 3
2 5 7 1 4""".split("\n")
input = lambda: data.pop(0)

# from sys import stdin
# input = stdin.readline

from math import ceil
attractionCount, dayVisits = map(int, input().split())
attractions = list(map(int, input().split()))
MAXDAYS = ceil(attractionCount/dayVisits)

# 1 indexed (fuck 0)
dp = [[-1 for _ in range(attractionCount + 1)] for _ in range(MAXDAYS + 1)]

# Fill first row of dp
curMax = attractions[0]
for k in range(dayVisits): dp[1][k+1] = curMax = max(curMax, attractions[k])

# fill dp
for day in range(2, MAXDAYS+1):
    print(f"Day {day}")

    # max as to not overshoot
    for endAttraction in range(day, max(day+dayVisits, attractionCount)):
        maxWay = 0
        for origin in range(day, endAttraction + 1):
            maxWay = max(maxWay, )
        dp[day][endAttraction] = maxWay

print("DP:")
[print(row) for row in dp]

print(dp[-1][-1])