finalSum = int(input())
fiveCount = finalSum % 4
fourCount = finalSum//4 - fiveCount
print(fourCount // 5 + 1)

# print((finalSum//4 - (finalSum % 4)) // 5 + 1) if you hate code readers