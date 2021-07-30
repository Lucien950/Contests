import sys
from collections import defaultdict
sys.setrecursionlimit(100100)

restoCount, pho = map(int, input().split())

#Set isPho correctly
phoList = list(map(int, input().split()))
isPho = [False] * restoCount
for i in phoList: isPho[i] = True

connections = []
[connections.append([]) for i in range(restoCount)]
#Set connections
for i in range(restoCount-1):
    x, y = map(int, input().split())
    connections[x].append(y)
    connections[y].append(x)

# tMaxDist = 0
# tMaxNodeOut = 0
# def dfs(start:int, prev:int, dist:int) -> (int, int):
#     global tMaxDist,tMaxNodeOut
#     for nextNodeI in connections[start]:
#         if nextNodeI == prev:
#             continue
#         toCurrent = dist + 1
#         if toCurrent > tMaxDist and isPho[nextNodeI]:
#             tMaxDist = toCurrent
#             tMaxNodeOut = nextNodeI
#         tMaxDist, tMaxNodeOut = dfs(nextNodeI, start, toCurrent)
#     return tMaxDist, tMaxNodeOut

def bfs(start:int, startDist:int):
    toExplore = {(start, startDist)}
    explored = [False] * restoCount
    maxDist = 0
    maxNode = None
    while toExplore:
        node, distance = toExplore.pop()
        if distance > maxDist and isPho[node]:
            maxDist = distance
            maxNode = node
        explored[node] = True
        for nextNode in connections[node]:
            if not explored[nextNode]:
                toExplore.add((nextNode, distance+1))
    return maxDist, maxNode

def solveSubTrees(start:int, prev:int = None) -> None:
    if prev is None:
        prev = start

    if isPho[start] and not subContainsPho[start]:
        subContainsPho[start] = True
    for nextNodeI in connections[start]:
        if nextNodeI == prev:
            continue
        solveSubTrees(nextNodeI, start)
        if subContainsPho[nextNodeI] and not subContainsPho[start]:
            subContainsPho[start] = True


#FIND ONE EXTREMITY
maxDistance, optimalStartingNode = bfs(phoList[0], 0)

subContainsPho = [False] * restoCount
#POPULATE THE ABOVE ARRAY

solveSubTrees(optimalStartingNode)
cost = (len([i for i in subContainsPho if i])-1)*2

#FIND THE OTHER EXTREMITY
maxDistance, optimalEndingNode =  bfs(optimalStartingNode, 0)
print(cost - maxDistance)