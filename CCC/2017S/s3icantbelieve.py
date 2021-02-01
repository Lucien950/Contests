from collections import defaultdict, Counter

n = int(input())
L = Counter(map(int, input().split()))
F=defaultdict(int)
maxl = 0
nmax = 1

for length in L:
    if L[length] > 1:
        F[length*2] += L[length]/2
    for length2 in {i for i in L if i > length}:
        F[length + length2] += min(L[length], L[length2])

for f in F:
    if F[f] > maxl:
        maxl = F[f]
        nmax = 1
    elif F[f] == maxl:
        nmax += 1

print(maxl, nmax)