from collections import defaultdict
from queue import PriorityQueue
penCount = int(input())
descriptions = [list(map(int, input().split())) for _ in range(penCount)]

adj = defaultdict(lambda: defaultdict(int))
penAdj  = defaultdict(lambda: defaultdict(lambda: float('inf')))
penConnections = set()
pensGivenEdgeBorders = defaultdict(list)
for penCount, i in enumerate(descriptions):
    connectionCount = i[0]
    nodes = i[1:1+connectionCount]
    weights = i[1+connectionCount:]
    for i in range(len(weights)):
        nextEdge = tuple(sorted([nodes[i], nodes[(i+1)%len(nodes)]]))
        adj[nextEdge[0]][nextEdge[1]] = weights[i]
        pensGivenEdgeBorders[nextEdge].append(penCount)

for edges, pens in pensGivenEdgeBorders.items():
    weight = adj[edges[0]][edges[1]]
    if len(pens) == 1: pens.append(-1) #go outside
    weight = min(weight, penAdj[pens[0]][pens[1]])
    penAdj[pens[0]][pens[1]] = weight
    penAdj[pens[1]][pens[0]] = weight
    penConnections.add((weight, pens[0], pens[1]))


cost = 0
explored = set()
edgePool = PriorityQueue()
[edgePool.put(edge) for edge in penConnections]
root = [i for i in range(penCount + 2)]
root[-1] = -1
while not(root[:-1] == [0] * (penCount + 1) or root == [-1] * (penCount + 2)) and not edgePool.empty():
    # build minimum spanning tree with prim's algorithm
    while True:
        if edgePool.empty(): break
        nextEdge = edgePool.get()
        if root[nextEdge[1]] != root[nextEdge[2]]: break
    if edgePool.empty(): break
    cost += nextEdge[0]

    pen1, pen2 = nextEdge[1], nextEdge[2]
    small = min(root[pen2], root[pen1])
    large = max(root[pen2], root[pen1])
    for i, pen in enumerate(root): 
        if pen == large: root[i] = small      
    
    # debug
    print(f"Connecting pens {nextEdge[1]} and {nextEdge[2]} with weight {nextEdge[0]}")

print(cost)