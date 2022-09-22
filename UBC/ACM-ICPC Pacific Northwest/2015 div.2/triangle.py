t1 = sorted(list(map(int, input().split())))
t2 = sorted(list(map(int, input().split())))

def isPy(t): return t[0] ** 2 + t[1] ** 2 == t[2] ** 2

if not(isPy(t1) and isPy(t2)): print("NO")
elif t1[0:2] != t2[0:2]: print("NO")
else: print("YES")