maxCapacity, farmNum, inspectionCount = map(int, input().split())

farms = []
inspections = []
for i in range(farmNum):
    farms.append(int(input()))
for i in range(inspectionCount):
    inspections.append(int(input()))


lastInspection = max(inspections)
dp = [[0 for i in range(farmNum + 1)] for j in range(lastInspection + 1)]
for i in farms:
    dp[0][i] += 1

for i in range(lastInspection):
    for index, value in enumerate(dp[i]):
        if value == 0:
            continue
        if index * 2 > maxCapacity:
            dp[i + 1][index] += value * 2
        else:
            dp[i + 1][index * 2] += value

for inspectionDay in inspections:
    print(sum(dp[inspectionDay]))
