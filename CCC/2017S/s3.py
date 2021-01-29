import math
from collections import Counter
from collections import defaultdict

woodCount = int(input())
woods = list(map(int, input().split()))
cc = Counter(woods)

dp = Counter()
maxWood = max(woods) + 1
for x in range(1, maxWood):
    for y in range(x, maxWood):
        toAdd = (math.floor(cc[x]/2) if x == y else min(cc[x], cc[y]))
        if toAdd != 0:
            dp[x+y] += toAdd

print(dp.most_common()[0][1])