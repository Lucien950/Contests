from collections import Counter

N = int(input())
arr = list(map(int, input().split()))
# a <= N <= 100 000
# 1 <= A_i <= 100 000

freq = Counter(arr)
correction, sum = 0, 0
adj = [0] * (10**5 + 1)

for x in range(1, 10**5 + 1):
    #Mark every third element in adjustment array with 3 if modulo 3 is 0
    for i in range(x, 10 ** 5 + 1, x):
        adj[i] += x * freq[x]
    correction += adj[x]
    sum += (x * N - correction) * freq[x] if freq[x] != 0 else 0

print(sum)



# SUBTASK 2
# freq = Counter(arr)

# sum = 0
# for i in range(1, 1001):
#     for j in range(1, 1001):
#         total += i % j * freq[i] * freq[j]
# print(sum)