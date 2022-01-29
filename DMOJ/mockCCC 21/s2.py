import sys
input = sys.stdin.readline
print(sum([abs(j - iIndex) for j, iIndex in zip(range(0, 2 * int(input()) - 2 + 1, 2), [i for i, x in enumerate(input()) if x == 'I'])]))