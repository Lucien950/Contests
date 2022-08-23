grid = [["*", "x", "*"],[" ", "x", "x"],["*", " ", "*"]]
factor = int(input())
for row in grid:
    line = ""
    for i in row:
        line += i*factor
    for _ in range(factor):
        print(line)