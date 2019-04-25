#INPUT HANDLING
l1 = input().split(" ")
NumFr = int(l1[0])
NumTyp = int(l1[1])
costs = input().split(" ")
#Converts all in costs to int
temp0 = []
for i in costs:
    temp0.append(int(i))
costs = temp0
fr = []
#Convert all in fr into int
for i in range(NumFr):
    fr.append(input().split(" "))
temp = []
for i in fr:
    tempInner = []
    for j in i:
        tempInner.append(int(j))
    temp.append(tempInner)
fr = temp

#Checks if all friends have the same oddity so funciton works.
remain = sum(fr[0])%2
works = True
for i in fr:
    if sum(i)%2 != remain:
        print("-1")
        works = False
        break

if works:
    if remain == 0:
        countCard = 1
    elif remain == 1:
        countCard = 2

    costs.sort()
    totCost = 0
    for i in range(countCard):
        totCost += costs[i]

    print(totCost)