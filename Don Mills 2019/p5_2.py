from sys import stdin
input = stdin.readline
n = int(input())
triplets = sorted([tuple(map(int, input().split())) for _ in range(n)])

def solve():
    i = 0
    while i < n-2:
        if triplets[i][2] != triplets[i+1][2] or triplets[i+1][2] != triplets[i+2][2]:
            return (i+1, i+2, i+3)
        i += 1
    return (-1, )

print(" ".join(map(str,solve())))