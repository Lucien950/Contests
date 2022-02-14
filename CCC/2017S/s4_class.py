data = """4 4 0
1 2 1
2 3 2
3 4 1
4 1 1""".split('\n')
input = lambda : data.pop(0)

# from sys import stdin
# input = stdin.readline
buildingCount, pipeCount, enhancerStrength = map(int, input().split())


pipes = [tuple(map(int, input().split())) + (i < buildingCount - 1, ) for i in range(pipeCount)]
pipes.sort(key=lambda x: x[2])
pipes.reverse()

usePipeCount = 0
time = 0
root = [i for i in range(buildingCount + 1)]
def find(a):
	if root[a] != a: root[a] = find(root[a])
	return root[a]

largestPipe = (-1, -1, -1, False)
while usePipeCount < buildingCount - 1:
	a, b, cost, inOriginal = pipes.pop()
	ra, rb = find(a), find(b)
	if ra == rb: continue
	if ra < rb:
		root[rb] = ra
	else:
		root[ra] = rb
	
	largestPipe = (a, b, cost, inOriginal)
	usePipeCount += 1
	if not inOriginal: time += 1



print(time)