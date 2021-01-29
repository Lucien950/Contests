from sys import getsizeof
cases = int(input())

high = 10**6
primes = []
isPrime = [1] * high
for factor in range(2, high):
    if isPrime[factor] == 1:
        primes.append(factor)
        for multiple in range(factor ** 2, high, factor):
            isPrime[multiple] = 0

for case in range(cases):
    bottom, top = map(int, input().split())
    count = 0
    for prime in primes:
        if bottom <= prime <= top:
            count += 1
        if prime > top:
            break
    print(count)