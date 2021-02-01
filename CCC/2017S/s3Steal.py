import math
from collections import Counter, defaultdict

woodCount = int(input())
woods = list(map(int, input().split()))
cc = Counter(woods)

dp = defaultdict(int)
for x in cc:
    for y in [i for i in cc if i > x]:
        toAdd = (math.floor(cc[x]/2) if x == y else min(cc[x], cc[y]))
        if toAdd != 0:
            dp[x+y] += toAdd

# print(dp.most_common()[0][1])

mh, ff = 0, 0
for i in dp:
    mh = max(mh, dp[i])
for i in dp:
    if dp[i] == mh:ff+=1

print(mh, ff)