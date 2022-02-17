spaces = int(input())
lastDay = input()
lastDay = list(lastDay)
toDay = input()
toDay = list(toDay)
value = 0
for index in range(spaces):
    if lastDay[index] == toDay[index] and lastDay[index] == "C":
        value += 1
print(value)