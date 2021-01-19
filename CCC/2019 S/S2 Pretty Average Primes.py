import random
cases = int(input())
avg = []
retVal = []
for i in range(cases):
    avg.append(int(input()))

def checkPrime(a):
    for i in range(round(a**0.5)+1):
        if i == 1 or i == 0:
            continue
        if a%i==0:
            return False
    return True

def findRecur(num):
    for a in range(2,num):
        if checkPrime(a) and checkPrime((num*2)-a):
            return [a, (num*2)-a]

for num in avg:
    retVal.append(findRecur(num))

for i in range(cases):
    print(str(retVal[i][0])+" "+str(retVal[i][1]))