from collections import Counter
N = int(input())
arr = list(map(int, input().split()))

total = correction = 0
frequency = Counter(arr)
adjust = [0] * (10**5 + 1)

for i in range(1, 10**5 + 1): # i % arr[j]
    # Mark the repeated subtraction for the next intervals
    for j in range(i, 10**5, i): # loop in segments of i
        adjust[j] += i * frequency[i]
    # Update the repeated subtraction
    correction += adjust[i]
    total += (i * N - correction) * frequency[i]

print(total)
