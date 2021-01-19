dists = input().split(" ")
goneDist = 0
for i in range(len(dists)):
    dists[i] = int(dists[i])
    goneDist += dists[i]
    dists[i] = goneDist
dists = [0] + dists

distTable = []
for i in range(len(dists)):
    addList = []
    start = dists[i]
    for item in dists:
        addList.append(abs(item-start))
    distTable.append(addList)

for i in distTable:
    returnlist = []
    for j in i:
        returnlist.append(j)
        returnlist.append(" ")
    for k in returnlist:
        print(k, end='')
    print("\n")