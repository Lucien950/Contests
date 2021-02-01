from timer import Timer
import heapq
class UnionFind:
    size = 0
    id = {}
    groups = 0

    numComponents = 0
    def __init__(self, size):
        if size <= 0:
            raise ValueError("Size must be greater than 0").with_traceback()
        self.size = self.numComponents = size
        self.id = dict([(i, i) for i in range(size)])

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
    def __repr__(self):
        return str(self.a) + " <- " + str(self.weight) + " -> " + str(self.b)


t = Timer()
def solve(func=input):
    t.start()
    buildingCount, pipeCount, enhancerStrength = tuple(map(int, func().split()))

    # Utility
    plan = UnionFind(buildingCount)
    onActions = 0
    offActions = 0

    #CONNECTIONS DELETE STUFF
    connectionsDelete = []
    for i in range(pipeCount):
        x, y, z = tuple(map(int, func().split()))
        connectionsDelete.append(Connection(x-1, y-1, z))
    connectionsDelete = list(zip([True]*(buildingCount-1) + [False]*(pipeCount-(buildingCount-1)), connectionsDelete))
    connectionsDelete.sort(key=lambda con:con[1].weight)

    #Main algorithm
    while not plan.oneGroup():
        isOn, nextConnect = connectionsDelete.pop(0)
        #If already connected
        if plan.find(nextConnect.a) == plan.find(nextConnect.b):
            if isOn: offActions += 1
            continue
        #Not Connected already
        else:
            if not isOn: onActions += 1
            plan.unify(nextConnect.a, nextConnect.b)

    #FINAL OUTPUT
    t.stop()
    return max(onActions, offActions)

for testNum in range(1,51):
    with open('./s4/s4.' + f"{testNum:02d}" + '.in') as file:
        print(testNum, str(solve(file.readline))==open('./s4/s4.' + f"{testNum:02d}" + '.out').read().rstrip())