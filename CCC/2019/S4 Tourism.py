import math
#Input Handling
firstLine = input().split(" ")#First line of input
stops = int(firstLine[0])#How many stops there are
stopPerDay = int(firstLine[1])#Maximum Stops per Day
places = input().split(" ")#List of points of places
temp = []
for i in places:
    temp.append(int(i))
places = temp
def roof(a):
    if math.floor(a) == a:
        return int(a)
    else:
        return int(math.floor(a)+1)
getDays = roof(stops/stopPerDay)#How many days we get

def topTwo(a, first, last):
    top = [0,0] #First index, then value
    second = [0,0] #~~~
    if last > len(a)-1:
        last = len(a)-1
    for i in range(first,last+1):
        try:
            if a[i] > top[1]:
                second[0] = top[0]
                second[1] = top[1]
                top[0] = i
                top[1] = a[i]
            elif a[i] > second[1] or (abs(top[0]-i) < abs(top[0]-second[0]) and a[i] == second[1]):
                second[0] = i
                second[1] = a[i]
        except:
            pass
    return [top[0], second[0]]

def lowest(a):
    if a[0] < a[1]:
        return a[0]
    else:
        return a[1]

minStep = math.floor(stops/stopPerDay)
maxStep = stopPerDay

splices = []
finishLine = 0

cutsLeft = getDays-1

while finishLine < len(places)-1:
    if cutsLeft == 0:
        finishLine = len(places)-1
    else:
        cutLine = topTwo(places, finishLine + minStep, finishLine + maxStep)
        finishLine = lowest(cutLine)
        splices.append(finishLine)
        cutsLeft -= 1

for i in range(len(splices)):
    