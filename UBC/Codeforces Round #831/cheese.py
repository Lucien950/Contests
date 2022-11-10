import sys
input = sys.stdin.readline
def solve():
	cheeseCount = int(input())
	cheeses = [sorted(map(int, input().split()), reverse=True) for _ in range(cheeseCount)]
	cheeses.sort()

	p = sum([2 * dim1 + 2 * dim2 for dim1, dim2 in cheeses])
	p -= sum([height for height, width in cheeses][:-1])*2
	return p

cases = int(input())
for case in range(cases):
	print(solve())