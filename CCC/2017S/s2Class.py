from math import ceil as roof
measurementCount = int(input())
measurements = sorted(list(map(int, input().split())))
# more low tide bias
highs, lows = measurements[roof(measurementCount/2):], measurements[:roof(measurementCount/2)][::-1]
a = []
for l,h in zip(lows, highs): a += [l,h]
if measurementCount % 2 != 0: a.append(lows[-1])
print(" ".join(map(str,a)))