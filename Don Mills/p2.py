mlist = input().split(" ")
temp =[]
for i in mlist:
    temp.append(int(i))
mlist = temp

if (mlist[0] > mlist[1] and mlist[0] > mlist[3]) and (mlist[2]>mlist[1] and mlist[2]>mlist[3]):
    print("trans")
elif (mlist[1] > mlist[0] and mlist[1] > mlist[2]) and (mlist[3]>mlist[0] and mlist[3]>mlist[2]):
    print("trans")
else:
    print("cis")