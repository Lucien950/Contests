def solve():
	# a smart solution would consider whether or not each point can extend two squares in any direction, given min(n, m) > 1
	# a smart solution would take more than 30 seconds to implement
	# thus I will not be implementing the smart solution
	n, m = map(int, input().split())
	if min(n, m) == 1:
		return "1 1"
	if max(n, m) >= 4:
		return "1 1"
	if n == m == 3 or min(n, m) == 2 and max(n, m) == 3:
		return "2 2"
	
	return "1 1"
	

cases = int(input())
for case in range(cases):
	print(solve())	