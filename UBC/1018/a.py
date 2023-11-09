t = int(input())
for i in range(t):
    n, l = int(input()), list(map(int, input().split()))
    sortedIndexes = sorted(range(n), key=lambda x: l[x], reverse=True)
    out = [0] * n
    for a, index in enumerate(sortedIndexes):
        out[index] = a + 1
    print(" ".join(map(str, out)))
