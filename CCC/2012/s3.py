from collections import Counter

sensorCount = int(input())
values = [int(input()) for _ in range(sensorCount)]
phCounter = Counter(values)

mostCommon, secondCommon = phCounter.most_common(2)


# CASE 1 most and second most common have the same frequency
# CASE 2 most and second most common have different frequencies, however second most common has similar frequency with other values
# tiebreaking
frequency = secondCommon[1]
yeet = sorted([i for i in phCounter.most_common() if i[1] == frequency], key=lambda x: x[0])
smallest, biggest = yeet[0][0], yeet[-1][0]
print(max(abs(mostCommon[0] - smallest), abs(mostCommon[0] - biggest)))