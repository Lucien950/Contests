# GeeTransit's solution. Submitting it to have a copy attached to my account
N = input()
n = len(N)
l, m, s = N.count("L"), N.count("M"), N.count("S")
L = N[:l]
M = N[l:l+m]
S = N[l+m:]
print(L.count("M") + L.count("S") + max(M.count("S"), S.count("M")))