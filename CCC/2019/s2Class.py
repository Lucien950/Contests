primeBools = [True] * 2000001
for i in range(2,1999993+1):
    if primeBools[i] == False: continue
    checkHead = i*2
    while checkHead <= 2000000:
        primeBools[checkHead] = False
        checkHead += i
def isPrime(n): return primeBools[n]

check = []
for _ in range(int(input())): check.append(int(input()))
for i in check:
    found = False
    for sum1 in range(2, i+1):
        sum2 = i*2 - sum1
        if isPrime(sum1) and isPrime(sum2) and sum1 + sum2 == i*2:
            print(sum1, sum2)
            found = True
            break
    if not found: print("FUCK")