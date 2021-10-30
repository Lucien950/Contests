def getHeight(m, x):
    # fucky wucky
    if m == 1: return [0, 1, 2, 1, 0][x]
    
    # GET THE VALUES FORM LAST LEVEL
    prevLevel = getHeight(m-1, x // 5)*5
    # Does not grow on places without existing crystals
    if prevLevel == 0: return 0

    # localX = x - x//5*5
    # ADDING THE BUMPS FOR THIS LEVEL
    return prevLevel + getHeight(1, x - x//5*5)

for case in range(int(input())):
    m, x, y = tuple(map(int, input().split()))
    caseHeight = getHeight(m, x)
    print("crystal" if y < caseHeight else "empty")

# getHeight test
# mag = int(input())
# print(" ".join(map(str, [getHeight(mag, i) for i in range(5**mag)])))
# exit()