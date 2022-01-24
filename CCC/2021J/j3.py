l = []
while True:
    a = input()
    if a == "99999": break
    l.append(a)

lastDir = ""
for i in l:
    direction, steps = i[0:2], i[2:]
    wordDir = ""
    summy = sum([int(i) for i in direction])
    if summy == 0: wordDir = lastDir
    elif summy % 2 == 0:wordDir = "right"
    else:wordDir = "left"
    print(wordDir, steps)
    lastDir = wordDir