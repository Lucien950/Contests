n = int(input())
responces = [input() for _ in range(n)]
# a = 0
# [a += 1 for i in range(n) if responces[i] == input()]
# print(a) 

answers = [input() for _ in range(n)]
print([a==b for a, b in zip(responces, answers)].count(True))