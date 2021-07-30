n = int(input())
heightList = list(map(int, input().split()))
widths = list(map(int, input().split()))

area = 0
for i in range(n):
    area += widths[i] * (heightList[i] + heightList[i + 1]) / 2.0

print(area)