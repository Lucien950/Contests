def overLap(lst1, lst2):
    lst3 = [value for value in lst1 if value in lst2]
    return lst3

friendNum = int(input())
giftList = list(map(int, input().split()))

emptyRecieve = list(range(1,friendNum + 1))
emptyGivers = []
for index in range(len(giftList)):
    if giftList[index] != 0:
        emptyRecieve.remove(giftList[index])
    else:
        emptyGivers.append(index + 1)

priority = overLap(emptyGivers, emptyRecieve)
for i in priority:
    emptyRecieve.remove(i)

for i in priority:
    for j in emptyGivers:
        if i != j-1:
            giftList[j-1] = i
            emptyGivers.remove(j)
            break

for i in emptyRecieve:
    for j in emptyGivers:
        giftList[j-1] = i

print(*giftList)