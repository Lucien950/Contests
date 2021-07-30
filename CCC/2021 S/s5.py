import math

n, m = map(int, input().split())


requirements = []
for i in range(m):
    a, b, c = map(int, input().split())
    requirements.append((a, b, c))

lister = [0]*(n+1)
for start, stop, gcd in requirements:
    for i in range(start, stop + 1):
        if lister[i] == 0:
            lister[i] = gcd
            continue
        if math.gcd(gcd, lister[i]) == 1:
            print("Impossible")
            exit()
        else:
            lister[i] = max(lister[i], gcd)

print(" ".join(map(str, lister[1:])))