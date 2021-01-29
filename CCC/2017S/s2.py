import math
days = int(input())
measures = sorted(tuple(map(int, input().split())))
lows = measures[:math.ceil(days/2)][::-1]
highs = measures[math.ceil(days/2):]

out = []
for low, high in zip(lows, highs):
    out.append(low)
    out.append(high)
if(days % 2 != 0):
    out.append(lows[len(lows) - 1])

print(' '.join(map(str, out)))