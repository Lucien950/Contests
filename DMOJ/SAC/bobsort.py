
# from random import randint
# arrayLength = 6
# a = []
# for _ in range(arrayLength):
#     a.append(randint(0, 100000))

from math import log, floor
input() # array length
a = list(map(int, input().split()))
lengthOfLongestElement = floor(log(max(a), 10) + 1)
for roundCount in range(1, lengthOfLongestElement + 1):
    a.sort(key=lambda x: int(str(x)[-roundCount]) if len(str(x)) >= roundCount else 0)
    print(" ".join(map(str, a)))