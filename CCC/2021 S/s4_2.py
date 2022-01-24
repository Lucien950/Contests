from sys import stdin
input = stdin.readline
n, w, d = map(int, input().split())
walkways = [tuple(map(int, input().split())) for _ in range(w)]
stations = {j:i for i, j in enumerate(map(int,input().split()))}
swaps = [(0, 0), tuple(map(int, input().split())) for _ in range(d)]

for s1, s2 in swaps:
    temp = stations[s1]
    stations[s1] = stations[s2]
    stations[s2] = temp

    for station in range(1,n):
        subwayTime = max(stations[station]-stations[n])
