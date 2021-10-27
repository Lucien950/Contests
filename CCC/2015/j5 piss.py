# recursive solution
pie = int(input())
people = int(input())

def countWays(pieces, people):
    piemap = dict()
    if pieces < people:
        # only invoked when giving everyone a pie
        return 0

    # part two is an optimization 👇
    if people == 1 or pieces == people:
        return 1

    removeOnePersonOnePie = countWays(pieces - 1, people - 1)
    giveEveryoneAPie=countWays(pieces - people, people)
    return removeOnePersonOnePie + giveEveryoneAPie

# tabulation DP solution
def countTabulate(pie, people):
    way = [[0 for i in range(people+1)] for j in range(pie+1)]
    way[0][1] = 1
    for pieCount in range(1, pie + 1):
        for peopleCount in range(1, min(people, pieCount) + 1):
            way[pieCount][peopleCount] = way[pieCount - 1][peopleCount - 1] + way[pieCount - peopleCount][peopleCount]
    return way[pie][people]


print(countWays(pie, people))
print(countTabulate(pie, people))