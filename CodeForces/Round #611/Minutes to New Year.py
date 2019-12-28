cases = int(input())

returnValue = []
for i in range(cases):
    line = input().split(" ")
    hour = int(line[0])
    minute = int(line[1])
    returnValue.append((23-hour)*60 + (60-minute))

for i in returnValue:
    print(i)
