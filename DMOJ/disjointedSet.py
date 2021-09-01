from sys import stdin

vertex, edges = map(int, stdin.readline().strip().split())
connections = []
for i in range(edges):
	connections.append(tuple(map(int, stdin.readline().strip().split())))

def root(vertexIndex: int):
	if cock[vertexIndex] == vertexIndex:
		return vertexIndex
	trueRoot = root(cock[vertexIndex])
	cock[vertexIndex] = trueRoot
	return trueRoot

cock = list(range(vertex))
sz = [1] * vertex
edgeCount = 1
out = []
components = vertex

connections.reverse()
while components > 1 and connections:
	v1, v2 = connections.pop()
	v1 -= 1
	v2 -= 1
	# if v1 has a base
	r1 = root(v1)
	r2 = root(v2)
	if r1 != r2:
		if sz[r1] < sz[r2]:
		# if r1 < r2:
			# attaches r1 under r2
			cock[r1] = r2
			sz[r2] += sz[r1]
		else:
			# attaches r2 under r1
			cock[r2] = r1
			sz[r1] += sz[r2]

		components -= 1
		out.append(edgeCount)
	edgeCount+=1

if components > 1:
	print("Disconnected Graph")
else:
	print("\n".join(map(str, out)))