import math
#In Triangle
def inTri(a,b,c,x):
    def areaTri(a,b,c):
        A = math.sqrt((b[0] - c[0]) ** 2 + (b[1] - c[1]) ** 2)
        B = math.sqrt((a[0] - c[0]) ** 2 + (a[1] - c[1]) ** 2)
        C = math.sqrt((b[0] - a[0]) ** 2 + (b[1] - a[1]) ** 2)
        S = (A + B + C) / 2
        return round(math.sqrt(S*(S-B)*(S-A)*(S-C)),14)
    a1=areaTri(b,c,x)
    b1=areaTri(a,c,x)
    c1=areaTri(b,a,x)
    aT=areaTri(a,b,c)
    if a1+b1+c1 == aT:
        return True
    else:
        return False


print(inTri([0,0], [0,3], [4,3], [1,2]))
numTri = int(input())
listofvalues = []

#input process to put values into one list
for i in range(numTri):
    a = input().split(' ')
    listofvalues.append(a)

#filter into red and blue triangles
listB = []
listR = []
for i in listofvalues:
    if i[2] == 1:
        listR.append(i)
    else:
        listB.append(i)

#filter possible triangles

#1 blue 2 red
listpossible = []
for a in listB:
    for b in listR:
        for c in listR:
            thetriangle = [a,b,c]
            listpossible.append(thetriangle)

for a in listR:
    for b in listB:
        for c in listB:
            thetriangle = [a,b,c]
            listpossible.append(thetriangle)

print(listpossible)
print(listB)




