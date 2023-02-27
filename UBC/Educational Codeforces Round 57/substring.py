import sys
def modFact(n, p):
    if n >= p:
        return 0   
    result = 1
    for i in range(1, n + 1):
        result = (result * i) % p
    return result

input = sys.stdin.readline
length = int(input().rstrip())
word = input().rstrip()

def solve():
	if len(set(word)) == 1:
		return modFact(length, 998244353)
	for l in range(length):
		if word[l] != word[0]:
			break
	for r in range(length):
		if word[length - 1 - r] != word[-1]:
			break
	if word[0] == word[-1]:
		return ((l + 1) * (r + 1)) % 998244353
	else:
		return l + r + 1

print(solve())