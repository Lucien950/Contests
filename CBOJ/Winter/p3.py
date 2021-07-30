from collections import defaultdict
spacerCount, gap = map(int, input().split())
spacers = sorted(list(map(int, input().split())))

dp = defaultdict(lambda: defaultdict(int))

def find(i: int, left:int):
    #DP???
    if dp[i][left] != 0:
        return dp[i][left]
    del dp[i][left]

    #HEY, YOU"VE FOUND IT! (NEXT ITERATION)
    if left == gap:
        return 0

    if i >= spacerCount:
        return float('inf')

    #Take
    take = find(i + 1, left+spacers[i])
    #don't take
    dont = find(i + 1, left)
    dp[i][left] = 1 + take if 1 + take <= dont else dont
    return dp[i][left]

def badFind(i:int, left:int) -> int or float:
    if left == gap:
        return 0
    if i >= spacerCount:
        return float('inf')
    take = badFind(i + 1, left + spacers[i])
    dont = badFind(i + 1, left)

    if 1 + take <= dont:return 1 + take
    else: return dont

ans = badFind(0, 0)
print(-1 if ans == float('inf') else ans)