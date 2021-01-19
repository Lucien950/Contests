def rotate(array,sLen):
    retArray = []
    ramList = []
    for i in range(sLen):
        for j in range(sLen):
            ramList.append(j,array[-i])
        retArray.append(ramList)
    return retArray

sFList = []
sideL = input()
for i in range(int(sideL)):
    sFList.append(input().split(" "))
print(sFList)