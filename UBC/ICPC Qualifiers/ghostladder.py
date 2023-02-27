a, rungCount = map(int, input().split())
rungs = [int(input()) for _ in range(rungCount)]

atCol = [element for element in range(1, a + 1)]
for rung in rungs:
	# move all from rung to rung+1
	# move all from rung+1 to rung
	atCol[rung - 1], atCol[rung] = atCol[rung], atCol[rung - 1]

print("\n".join(map(str, atCol)))