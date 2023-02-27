from math import ceil
def solve():
	towerCount = int(input())
	towers = list(map(int, input().split()))
	# print(sum(towers[1:]))
	if(towers[0] == max(towers)):
		return towers[0]
	
	bestTower = towers[0]
	rest = filter(lambda x: x > towers[0], sorted(towers[1:]))
	for otherTower in rest:
		bestTower = ceil((bestTower + otherTower)/2)
	return bestTower
	
cases = int(input())
for case in range(cases):
	print(solve())