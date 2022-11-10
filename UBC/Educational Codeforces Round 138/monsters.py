def solve():
	monsterCount = int(input())
	monsterHealth = list(map(int, input().split()))
	monsterSpell = list(map(int, input().split()))

	# we want to know *total damage dealt
	# all the values in monster health will inevitably added to the total damage dealt, so they can just be added
	# every time a heal is applied, you can consider that directly into the total damage (required to be) dealt category
	# kill enemies on the edge = only apply heal to 1 other enemy -> thus count that heal only once
	# last enemy dead = no apply heal -> thus count no times
	# add sum of all spell values without the maximum spell
	return sum(monsterHealth) + (sum(monsterSpell) - max(monsterSpell))

cases = int(input())
for case in range(cases):
	print(solve())