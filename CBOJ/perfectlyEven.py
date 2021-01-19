# import math
#
# limit = int(input())
#
# firstNum = math.floor(int(str(limit)[0])/2) * 2
#
# final = len(range(0, firstNum + 1, 2))
# for i in range(len(str(limit))-1):
#     final *= 5
#
# print(final)


# def calc(num, LIMIT):
#     if num >= LIMIT:
#         return 0
#     total = 1
#     for dig in [0, 2, 4, 6, 8]:
#         total += calc(num * 10 + dig, LIMIT)
#     return total
#
# LIMIT = int(input())
# total = 0
# for leftmost in [2, 4, 6, 8]:
#     total += calc(leftmost, LIMIT)
# print(total)


runTimes = int(input())

for i in range(runTimes):
    print(sum(map(int, input().split())))