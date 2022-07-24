booths = int(input()) # also the length of the lines

studentsInLine = [0 for _ in range(booths)]
for i in range(booths):
    row = list(input())
    for i in range(booths):
        studentsInLine[i] += 1 if row[i] == "S" else 0

for row in range(booths,0,-1):
    rowString = ""
    for i in range(booths):
        rowString += "S" if studentsInLine[i] >= row else "."
    print(rowString)