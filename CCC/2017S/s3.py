from collections import Counter
from math import floor

def boards_at_height(h):
    pairs = [(i, h-i) for i in range(1, h//2 + 1)]
    out = 0
    for a, b in pairs:
        if a in bCounter and b in bCounter:
            out += min(bCounter[a], bCounter[b]) if not a == b else floor(bCounter[a]/2)
    return out

boardCount = int(input())
# 2 ≤ N ≤ 1000000
bCounter = Counter(map(int, input().split()))
# 1 ≤ L_i ≤ 2000


l = w = 0
h = []
for height in range(2, 4001):
    b = boards_at_height(height)
    if b > l:
        l, w = b, 0
        h = []
    if b == l:
        w += 1
        h.append(height)

print(l,w)


# for fileNum in range(1, 29):
#     with open(f'./senior_data/s3/s3.{fileNum:02d}.in') as file:
#         boardCount = int(file.readline())
#         # 2 ≤ N ≤ 1000000
#         bCounter = Counter(map(int, file.readline().split()))
#         # 1 ≤ L_i ≤ 2000
#
#
#         l = w = 0
#         h = []
#         for height in range(2, 4001):
#             b = boards_at_height(height)
#             if b > l:
#                 l, w = b, 0
#                 h = []
#             if b == l:
#                 w += 1
#                 h.append(height)
#
#         # print(l,w)
#         # print(h)
#         print(str(l) + " " + str(w) == open(f'./senior_data/s3/s3.{fileNum:02d}.out').read().rstrip())