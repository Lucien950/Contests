from sys import stdin
input = stdin.readline
n = int(input())
a = map(int, input().split())
q = int(input())
queries = []
for i in range(q):
	queries.append(int(input()))

psa = [0]
for i, e in enumerate(a):
	psa.append(psa[i]+e)

for query in queries:
	print(psa[query])