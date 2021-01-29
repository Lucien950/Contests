t1, t2, left, right = map(int, input().split())

q1 = list(map(int, input().split()))
q2 = list(map(int, input().split()))

def excecute(terms, x):
    return sum([term * pow(x, exp) for exp, term in list(enumerate(terms))])

def sign(x):
    return excecute(q1, x) > excecute(q2, x)

for i in range(100):
    mid = (right + left)/2.0
    if sign(left) != sign(mid):
        right = mid
    else:
        left = mid

print(left, excecute(q1, left))