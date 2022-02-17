import random
#Input Work
table = []
temptable = []
for row in range(3):
    temptable.append(input().split(" "))
for row in temptable:
    temp = []
    for item in row:
        try:
            temp.append(int(item))
        except:
            temp.append(item)
    table.append(temp)

#Functions
def avg(list):
    avgList = []
    for i in list:
        try:
            avgList.append(int(i))
        except:
            pass
    return int(sum(avgList)/len(avgList))


xContain = True
while xContain:
    for row in table:
        if "X" in row:
            if len([index for index, value in enumerate(row) if value == "X"]) > 2:
                pass
            else:
                table[table.index(row)][row.index("X")] = avg(row)
    #Check for X's
    checkList = False
    for line in table:
        if "X" in line:
            checkList = True
    if checkList == False:
        xContain = False


#Output Work
for row in table:
    temp = ""
    for i in row:
        temp += str(i)
        temp += " "
    temp = temp[:-1]
    print(temp)