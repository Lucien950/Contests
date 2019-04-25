import math
#In Triangle
def inTri(a,b,c,x):
    def MidPoint(a,b):
        mx = a[0]-b[0]
        my = a[1]-b[1]
        return [mx,my]
    def Length(a,b):
        length = math.sqrt(abs((a[0]-b[0]))**2+abs((a[1]-b[1]))**2)
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

print(inTri([0,0], [0,3], [3,4], [1,2]))