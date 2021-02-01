from itertools import accumulate

stations, lines, actions = map(int, (input().split()))
# 1 ≤ lines ≤ stations ≤ 150 000,  1 ≤ actions ≤ 150 000

lineNum = list(map(int, input().split()))
passengers = list(map(int, input().split()))

passengersAccum = accumulate(passengers)


#FUNCTIONAL PROGRAMMING!!!!!
def act1(l, r):
    print(sum(passengers[l-1:r]))


def act2(line):
    nodes = [i for i, x in enumerate(lineNum) if x == line]
    temp = passengers[nodes[-1]]
    for lastNodeIndex, nodeIndex in reversed(tuple(zip(tuple(range(len(nodes)-1)), tuple(range(1,len(nodes)))))):
        passengers[nodes[nodeIndex]] = passengers[nodes[lastNodeIndex]]
    passengers[nodes[0]] = temp


for i in range(actions):
    yee = tuple(map(int, input().split()))
    action = yee[0]
    if action == 1:
        l, r = yee[1:]
        act1(l, r)
    elif action == 2:
        line = yee[1]
        act2(line)
    else:
        raise Exception("Gay action")