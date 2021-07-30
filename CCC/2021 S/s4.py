n, w, d = map(int, input().split())
stations = []
walkways = []
swaps = []

#TAKE INPUT
for i in range(w):
    walkways.append(tuple(map(int, input().split())))
stations = [0] + list(map(int,input().split()))
for i in range(d):
    swaps.append(tuple(map(int, input().split())))


posOfStation = {}
for i, station in enumerate(stations):
    posOfStation[station] = i

for a, b in swaps:
    #SWAP THE STATIONS
    tempA = stations[a]
    tempB = stations[b]
    #GET THE POINT POINTING RIGHT
    posOfStation[tempA] = b
    posOfStation[tempB] = a
    #SWIPPITY SWAP
    stations[a] = tempB
    stations[b] = tempA

    route = list(range(posOfStation[1]*-1, n-posOfStation[1] + 1))
    route[0] = 0
    for x, y in walkways:
        if route[posOfStation[y]] > route[posOfStation[x]] + 1:
            route[posOfStation[y]] = route[posOfStation[x]] + 1
            counteee = route[posOfStation[y]] + 1
            pointee = posOfStation[y] + 1
            while pointee <= n:
                if route[pointee] <= counteee:
                    break
                route[pointee] = counteee
                counteee += 1
                pointee += 1
    print(route[posOfStation[n]])