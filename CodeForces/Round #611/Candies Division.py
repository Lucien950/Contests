import math

cases = int(input())

returnValue = []
for i in range(cases):  # Ran for every case
    inList = input().split(" ")
    candies = int(inList[0])
    kids = int(inList[1])
    leftOver = (candies%kids)
    if leftOver == 0:#Find perfect division
        returnValue.append(candies)
    else:
        leftOver -= math.floor(kids/2)#Give each kid one extra candy
        if leftOver <= 0:
            returnValue.append(candies)
        else:
            returnValue.append(candies-leftOver)

for i in returnValue:
    print(i)