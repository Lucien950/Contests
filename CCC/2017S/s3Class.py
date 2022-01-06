from collections import Counter, defaultdict
woodCount = int(input())

# given length of board, how many boards are there?
boardCount = Counter(map(int, input().split()))

# how many ways can we make a certain height by adding two pieces of wood together?
heights = defaultdict(int)

for board1 in boardCount:
    for board2 in boardCount:
        if board2 < board1: continue
        if board2==board1: heightCount = boardCount[board1] >> 1 # boardCount[board2] also works
        else: heightCount = min(boardCount[board1],boardCount[board2])
        if heightCount == 0:continue
        heights[board1 + board2] += heightCount 

longestFence = differentHeightstoMake = 0
for height, fenceLegth in heights.items():
    if fenceLegth > longestFence:
        longestFence = fenceLegth
        differentHeightstoMake = 1
    elif fenceLegth == longestFence:
        differentHeightstoMake += 1
print(longestFence, differentHeightstoMake)