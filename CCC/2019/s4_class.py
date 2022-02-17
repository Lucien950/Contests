data ="""5 3
5 5 1 1 1""".split("\n")
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
    for endAttraction in range(day, min(day*dayVisits, attractionCount+1)):
        maxVal = 0
        for origin in range(day, endAttraction + 1):
            lastRange = dp[day-1][origin-1]
            if lastRange == -1: continue
            maxVal = max(maxVal, lastRange + max(attractions[origin-1:endAttraction]))
        dp[day][endAttraction] = maxVal

# print("DP:")
# [print(row) for row in dp]

if dp[-1][-1] == 2000000000: print(attractionCount, dayVisits)
print(dp[-1][-1])