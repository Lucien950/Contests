from collections import defaultdict, Counter
spacerCount, gap = map(int, input().split())
spacers = map(int, input().split())

sums = defaultdict(int)
for i in spacers:
    sums[i] = 1
i = 0
while sums[spacerCount] is 0:

    i += 1