import math
#In Triangle
def areaTri(a, b, c):
    A = math.sqrt((b[0] - c[0]) ** 2 + (b[1] - c[1]) ** 2)
    B = math.sqrt((a[0] - c[0]) ** 2 + (a[1] - c[1]) ** 2)
    C = math.sqrt((b[0] - a[0]) ** 2 + (b[1] - a[1]) ** 2)
    S = (A + B + C) / 2
    return round(math.sqrt(S * (S - B) * (S - A) * (S - C)), 13)
def inTri(a,b,c,x):
    a1=areaTri(b,c,x)
    b1=areaTri(a,c,x)
    c1=areaTri(b,a,x)
    aT=areaTri(a,b,c)
    if a1+b1+c1 == aT:
        return True
    else:
        return False

#Makes List of Red Points and Blue Points
numTri = int(input())
listofvalues = []

#input process to put values into one list
for i in range(numTri):
    a = input().split(' ')
    temp = []
    for j in a:
        temp.append(int(j))
    a=temp
    listofvalues.append(a)

#filter into red and blue triangles
listB = []
listR = []
for i in listofvalues:
    if i[2] == 1:
        listR.append(i)
    else:
        listB.append(i)


#Makes a list of possible Triangles
listpossible = []

# 1blue 2red
for a in listB:
    for b in listR:
        for c in listR:
            if b != c:
                thetriangle = [a,b,c]
                listpossible.append(thetriangle)
# 2blue 1red
for a in listR:
    for b in listB:
        for c in listB:
            if b != c:
                thetriangle = [a,b,c]
                listpossible.append(thetriangle)

ansTri = []
for tri in listpossible:
    if areaTri(tri[0], tri[1], tri[2]) == 0:
        ansTri = tri
        break
    else:
        count = 0
        for co in listofvalues:
            if co in tri:
                count += 1
            elif inTri(tri[0],tri[1],tri[2],co):
                break
            else:
                count += 1
        if count == len(listofvalues):
            ansTri = tri
            break
ans = ""
for co in ansTri:
    ans += str(listofvalues.index(co)+1)
    ans += " "
slicei = len(ans)-1
ans = ans[:slicei]
print(ans)