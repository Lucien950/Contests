friendCount = int(input())
friendLists = [[], [], []]
cutOffs = [0, 0, 0]
for friend in range(friendCount):
    contacts, friendName = input().split()
    phoneTypeCount = [0, 0, 0]
    for contact in range(int(contacts)):
        n = [int(char) for twoChar in input().split("-") for char in twoChar]
        if all([i == n[0] for i in n[1:]]):
            phoneTypeCount[0] += 1
        elif all([ch < n[i - 1] for i, ch in list(enumerate(n))[1:]]):
            phoneTypeCount[1] += 1
        else:
            phoneTypeCount[2] += 1
    for i in range(3):
        if phoneTypeCount[i] > cutOffs[i]:
            cutOffs[i] = phoneTypeCount[i]
            friendLists[i] = [friendName]
        elif phoneTypeCount[i] == cutOffs[i]:
            friendLists[i].append(friendName)
print(f"If you want to call a taxi, you should call: {', '.join(friendLists[0])}.")
print(f"If you want to order a pizza, you should call: {', '.join(friendLists[1])}.")
print(f"If you want to go to a cafe with a wonderful girl, you should call: {', '.join(friendLists[2])}.")
