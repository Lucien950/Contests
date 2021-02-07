from collections import defaultdict
class UnionFind:
    size = 0
    id = {}
    groups = 0
    sz = {}

    numComponents = 0
    def __init__(self, size):
        if size <= 0:
            raise ValueError("Size must be greater than 0").with_traceback()
        self.size = self.numComponents = size
        self.id = dict([(i, i) for i in range(size)])
        self.sz = dict([(i, 1) for i in range(size)])

    #Find the root of a target
    def find(self, target):
        #While the target doesn't point to itself
        while target != self.id[target]:
            self.id[target] = self.id[self.id[target]]
            target = self.id[target]
        return target
    def connected(self, a, b):
        return self.find(a) == self.find(b)

    def components(self):
        return self.numComponents

    def unify(self, a, b):
        root1 = self.find(a)
        root2 = self.find(b)
        if root1 == root2:
            raise Exception("Dumbo")
        if self.sz[root1] >= self.sz[root2]:
            self.id[root2] = self.id[root1]
            self.sz[root1] += self.sz[root2]
        else:
            self.id[root1] = self.id[root2]
            self.sz[root2] += self.sz[root1]
        self.numComponents -= 1

    def oneGroup(self):
        return self.numComponents == 1
class Connection:
    def __init__(self, a:int, b:int, weight:int, sOn:int):
        self.a = a
        self.b = b
        self.weight = weight
        self.sOn = sOn
    def __str__(self):
        return str(self.a) + " <- "+ str(self.weight) + " -> " + str(self.b)
    def __repr__(self):
        return str(self.a) + " <- " + str(self.weight) + " -> " + str(self.b)

def solve(func=input):
    buildingCount, pipeCount, enhancerStrength = map(int, func().split())

    # Utility
    plan = UnionFind(buildingCount)
    onActions = 0
    offActions = 0

    #CONNECTIONS DELETE STUFF
    connectionsList = []
    for i in range(pipeCount):
        x, y, z = tuple(map(int, func().split()))
        connectionsList.append(Connection(x-1, y-1, z, i < buildingCount-1))
    connectionsList.sort(key=lambda con:con.weight)
    connectionsList.reverse()

    #Main algorithm
    usedConnections = defaultdict(defaultdict) #WITH FORM ORIGIN:[(Destination, weight)]
    while not plan.oneGroup():
        nextConnect = connectionsList.pop()
        #If already connected
        if plan.find(nextConnect.a) == plan.find(nextConnect.b):
            if nextConnect.sOn: offActions += 1
            continue
        #Not Connected already
        else:
            if not nextConnect.sOn: onActions += 1
            # usedConnections[nextConnect.a][nextConnect.b]= nextConnect.weight
            plan.unify(nextConnect.a, nextConnect.b)

    #Is it Day, or Day - 1?
    # if not enhancerStrength==0:
    #     for a, b, weight in connectionsList:
    #         oldWeight = usedConnections[a][b]

    #FINAL OUTPUT
    return max(onActions, offActions)

# print(solve())

for testNum in range(1,51):
    with open('./senior_data/s4/s4.' + f"{testNum:02d}" + '.in') as file:
        print(testNum, str(solve(file.readline))==open('./senior_data/s4/s4.' + f"{testNum:02d}" + '.out').read().rstrip())