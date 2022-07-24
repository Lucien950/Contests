intersectCount, schoolDistance = map(int, input().split())
lights = []
for i in range(intersectCount):
    position, red, green = map(int, input().split())
    lights.append((position, red, green))

timeNeed = 0
P = 0
for p, r, g in lights:
    # go to next light
    timeNeed += p - P
    P = p
    # wait for red
    cycle = r + g
    localCycleTime = timeNeed % cycle
    if localCycleTime <= r:
        timeNeed += r - localCycleTime

# go from last light to the end
timeNeed += schoolDistance - P
print(timeNeed)