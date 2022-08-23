lines = int(input())
for _ in range(lines):
    line = input()
    prevChar = None
    out = []
    streak = 0
    for c in line:
        if prevChar == None:
            prevChar = c
            continue
        
        if c == prevChar:
            streak += 1
            continue
        else:
            out.append(str(streak + 1))
            out.append(prevChar)
            streak = 0
            prevChar = c
    out.append(str(streak + 1))
    out.append(prevChar)
    print(" ".join(out))