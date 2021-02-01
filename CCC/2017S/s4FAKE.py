pointTo = list(range(1000005))
def root(node:int):
    while node != pointTo[node]:
        #Optimization
        pointTo[node] = pointTo[pointTo[node]]
        node = pointTo[node]
    return node

def merge(a:int, b:int):
    x = root(a)
    y = root(b)
    pointTo[x] = y



buildingsCount, pipeCount, enhancer = map(int, input().split())

edges = []
for _ in range(pipeCount):
    edges.append(tuple(map(int, input().split())))

edges.sort(key=lambda a: a[2])

final = 0
for i, (start, end, weight) in enumerate(edges):
    if root(start) != root(end):
        if i >= buildingsCount:
            final += 1
        merge(start, end)

print(final)