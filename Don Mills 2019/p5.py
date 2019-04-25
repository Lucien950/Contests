import math
#In Triangle
def inTri(a,b,c,x):
    def MidPoint(a,b):
        mx = a[0]-b[0]
        my = a[1]-b[1]
        return [mx,my]
    def Length(a,b):
        length = math.sqrt((a[0]-b[0])^2+(a[1]-b[1])^2)
        return length
    h=Length(a,b)
    w=Length(MidPoint(a,b), x)
    a1 = (h*w)/2
    h = Length(a, c)
    w = Length(MidPoint(a, c), x)
    a2 = (h * w) / 2
    h = Length(c, b)
    w = Length(MidPoint(c, b), x)
    a3 = (h * w) / 2
    h = Length(MidPoint(a, b),c)
    w = Length(a,b)
    triA = (h * w)/2
    if a1 + a2 + a3 == triA:
        return 0
    else:
        return 1

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




