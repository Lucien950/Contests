import sys
sys.setrecursionlimit(100100)

class Node:
    __slots__ = ['id', 'isPho', 'connections']
    def __init__(self, id:int):
        self.id = id
        self.isPho = False
        self.connections = set()

restoCount, pho = map(int, input().split())

# Add all nodes
nodes = []
for i in range(restoCount):
    nodes.append(Node(i))

#Set isPho correctly
firsty = None
for yeeter in map(int, input().split()):
    if firsty is None:
        firsty = yeeter
    nodes[yeeter].isPho = True

#Set connections
for i in range(restoCount-1):
    x, y = map(int, input().split())
    nodes[x].connections.add(y)
    nodes[y].connections.add(x)

tMaxDist = 0
tMaxNodeOut = 0
def dfs(start:int, prev:int, dist:int) -> (int, Node):
    global tMaxDist,tMaxNodeOut
    for nextNodeI in nodes[start].connections:
        if nextNodeI == prev:
            continue
        toCurrent = dist + 1
        if toCurrent > tMaxDist and nodes[nextNodeI].isPho:
            tMaxDist = toCurrent
            tMaxNodeOut = nextNodeI
        tMaxDist, tMaxNodeOut = dfs(nextNodeI, start, toCurrent)
    return tMaxDist, tMaxNodeOut

# def bfs(start:int, startDist:int):
#     toExplore = {(start, startDist)}
#     explored = set()
#     maxDist = 0
#     maxNode = None
#     while toExplore:
#         node, distance = toExplore.pop()
#         if distance > maxDist and nodes[node].isPho:
#             maxDist = distance
#             maxNode = node
#         explored.add(node)
#         for nextNode in nodes[node].connections:
#             if nextNode not in explored:
#                 toExplore.add((nextNode, distance+1))
#     return maxDist, maxNode

def solveSubTrees(start:int, prev:int = None) -> None:
    if prev is None:
        prev = start

    if nodes[start].isPho and not subContainsPho[nodes[start].id]:
        subContainsPho[start] = True
    for nextNodeI in nodes[start].connections:
        if nextNodeI == prev:
            continue
        solveSubTrees(nextNodeI, start)
        if subContainsPho[nodes[nextNodeI].id] and not subContainsPho[start]:
            subContainsPho[start] = True


#FIND ONE EXTREMITY
maxDistance, optimalStartingNode = dfs(firsty, firsty, 0)

subContainsPho = [False] * restoCount
#POPULATE THE ABOVE ARRAY

solveSubTrees(optimalStartingNode)
cost = (len([i for i in subContainsPho if i])-1)*2

#FIND THE OTHER EXTREMITY
maxDistance, optimalEndingNode =  dfs(optimalStartingNode, optimalStartingNode, 0)
print(cost - maxDistance)
if cost - maxDistance == 100777:
    print(sys.getsizeof(nodes))