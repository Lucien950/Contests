from sys import stdin
input = stdin.readline
people, compareCount = map(int, input().split())

taller = [-1] + [[] for _ in range(people)]

for i in range(compareCount):
    x, y = map(int, input().split())
    taller[y].append(x)

def bfs(start, find):
    explored = [False] + [False for _ in range(people)]
    queue = set(taller[start])  
    while queue:
        node = queue.pop()
        if node == find: return True
        for neighbor in taller[node]:
            if explored[neighbor]: continue
            queue.add(neighbor)
            explored[neighbor] = True
    return False

p, q = map(int, input().split())
# check p > q
if bfs(q, p):
    print('yes')
# check p < q
elif bfs(p, q):
    print("no")
# fuck it
else:
    print("unknown")