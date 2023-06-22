from collections import defaultdict


def getSubLengths(l: list[int]):
    lsubs: defaultdict[int, int] = defaultdict(int)
    streak = 1
    for i, thisEl in enumerate(l):
        lastEl = l[i-1]
        if i == 0: continue
        if thisEl == lastEl: streak += 1
        else:
            lsubs[lastEl] = max(streak, lsubs[lastEl])
            streak = 1
    lsubs[l[-1]] = max(streak, lsubs[l[-1]])
    return lsubs


cases = int(input())
for case in range(cases):
    n = int(input())
    l1, l2 = [list(map(int, input().split())) for _ in range(2)]
    l1Sub, l2Sub = getSubLengths(l1), getSubLengths(l2)

    vals = {*l1Sub.keys(), *l2Sub.keys()}
    streaks = map(lambda x: l1Sub[x] + l2Sub[x], vals)
    ans = max(streaks)
    print(ans)
