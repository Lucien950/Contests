from collections import Counter

N = int(input())
M = int(input())

K = int(input())
choices = []
for i in range(K):
    direction, num = input().split()
    num = int(num)
    choices.append((direction, num))

cChoices = Counter(choices)
for i in cChoices:
    cChoices[i] = cChoices[i] % 2
cChoices += Counter()
choices = list(cChoices)

grid = [[False for i in range(M)] for j in range(N)]

for direction, number in choices:
    if direction == "R":
        grid[number-1] = [not i for i in grid[number - 1]]
    elif direction == "C":
        for i in range(N):
            grid[i][number - 1] = not grid[i][number - 1]

tally = 0
for row in grid:
    for item in row:
        if item:
            tally += 1

print(tally)