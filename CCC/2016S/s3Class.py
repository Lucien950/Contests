import sys
input = sys.stdin.readline
sys.setrecursionlimit(100100)

restCount, phoCount = map(int, input().split())
phoIndexes = list(map(int, input().split()))
isPho = [i in phoIndexes for i in range(restCount)]
adj = [[] for _ in range(restCount)]
for i in range(restCount-1):
    r1, r2 = map(int, input().split())
    adj[r1].append(r2)
    adj[r2].append(r1)

def findFurthest(startingNode):
    # find the furthest pho from the first pho
    toExplore = {(startingNode, 0)}
    explored = [False] * restCount
    maxDistance, maxNode = 0, None

    while toExplore:
        curr, distance = toExplore.pop()
        if distance > maxDistance and isPho[curr]: maxDistance, maxNode = distance, curr
        explored[curr] = True
        # for every path that is connected to the current pho
        for next in adj[curr]:
            if explored[next]: continue
            toExplore.add((next, distance + 1))
    return maxDistance, maxNode

_, optimalStartingNode = findFurthest(phoIndexes[0])
shortDistance, optimalEndingNode = findFurthest(optimalStartingNode)

# every node gets travelled twice. how much travel do we do?
subContainsPho = [False] * restCount
def solveSubTrees(start:int, prev:int = None) -> None:
    if prev is None: prev = start
    if isPho[start] and not subContainsPho[start]: subContainsPho[start] = True
    for nextNodeI in adj[start]:
        if nextNodeI == prev: continue
        solveSubTrees(nextNodeI, start)
        if subContainsPho[nextNodeI] and not subContainsPho[start]:
            subContainsPho[start] = True

solveSubTrees(optimalStartingNode)
cost = (subContainsPho.count(True)-1)*2
print(cost-shortDistance)

# choco1123yale@gmail.com