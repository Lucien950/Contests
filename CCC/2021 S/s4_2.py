from email.policy import default
from sys import stdin
from collections import defaultdict

input = stdin.readline
n, w, d = map(int, input().split())
walkways = [tuple(map(int, input().split())) for _ in range(w)]
stations = {j:i for i, j in enumerate(map(int,input().split()))}
swaps = [(1, 1)]+[tuple(map(int, input().split())) for _ in range(d)]

walkAdj = defaultdict(list)
for to, f in walkways:
	walkAdj[to].append(f)
walkWeights = [-2]+[-1 for _ in range(n)]
walkWeights[-1]=1
queue = {4}
visited = [False for _ in range(n)]
while queue:
	node = queue.pop()
	for next in walkAdj[node]:
		if visited[next]: continue
		walkWeights[next] = walkWeights[node] + 1
		visited[next] = True
		queue.add(next)
for s1, s2 in swaps:
	temp = stations[s1]
	stations[s1] = stations[s2]
	stations[s2] = temp
	