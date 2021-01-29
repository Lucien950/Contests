class UnionFind:
    size = 0
    sz = []
    id = []
    groups = 0

    numComponents = 0
    def __init__(self, size):
        if size <= 0:
            raise ValueError("Size must be greater than 0").with_traceback()
        self.size = self.numComponents = size
        self.id=[None] * size
        self.sz=[None] * size
        for i in range(size):
            self.id[i] = i
            self.sz[i] = 1

    #Find the root of a target
    def find(self, target):
        root = target
        while root != self.id[root]:
            root = self.id[root]
        while target != root:
            next = self.id[target]
            self.id[target] = root
            target = next
        return root
    def connected(self, a, b):
        return self.find(a) == self.find(b)

    def componentSize(self, p):
        return self.sz[self.find(p)]

    def size(self):
        return self.size

    def components(self):
        return self.numComponents

    def unify(self, a, b):
        root1 = self.find(a)
        root2 = self.find(b)
        self.sz[min(root1, root2)] += self.sz[max(root1, root2)]
        self.id[max(root1, root2)] = self.id[min(root1, root2)]
        self.numComponents -= 1

    def oneGroup(self):
        return self.numComponents == 1


class Connection:
    def __init__(self, a:int, b:int, weight:int):
        self.a = a
        self.b = b
        self.weight = weight
    def __str__(self):
        return str(self.a) + " <- "+ str(self.weight) + " -> " + str(self.b)

buildingCount, pipeCount, enhancerStrength = tuple(map(int, input().split()))

connections = []
for i in range(pipeCount):
    x, y, z = tuple(map(int, input().split()))
    connections.append(Connection(x-1, y-1, z))

connections.sort(key=lambda con:con.weight)

plan = UnionFind(buildingCount)

while not plan.oneGroup():
    nextConnect = connections.pop(0)
    plan.unify(nextConnect.a, nextConnect.b)

#DEACTIVATIONS
print(len(connections))

#The connections in UnionFind
# print(plan.id)
# All connections
# [print(c) for c in connections]