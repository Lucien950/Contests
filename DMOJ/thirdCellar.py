import math

cases = int(input())
# Sieve[1] = if r is prime
sieve = [True] * 1000001
sieve[0] = False
sieve[1] = False
for j in range(2, 1001):
	if not sieve[j]:
		# is a composite whose primes have already been checked
		# ex. 6, 2 and 3 have all been checked already.
		continue
	checkPrime = j * 2
	while checkPrime < 1000000:
		sieve[checkPrime] = False
		checkPrime += j
# [print(i, j) for i,j in enumerate(map(str, sieve[0:1000]))]
for i in range(cases):
	l, r = map(int, input().split())
	print(sieve[l:r].count(True))