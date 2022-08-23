a = [[1, 2], [3, 4]]
for move in list(input()):
    if move == "H":
        a = a[::-1]
    elif move == "V":
        a = [row[::-1] for row in a]
print("\n".join([" ".join(map(str, row)) for row in a]))