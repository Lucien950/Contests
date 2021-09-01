pie = int(input())
people = int(input())
way = [[0 for i in range(people+1)] for j in range(pie+1)]
way[0][1] = 1
for i in range(1, pie+1):
    for j in range(1, min(people, i)+1):
        way[i][j] = way[i-1][j-1] + way[i-j][j]
print(way[pie][people])