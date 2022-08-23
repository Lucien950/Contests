hairLength = int(input())
hairRemovedPerCut = int(input())
cutCount = int(input())
for i in range(cutCount):
    hairLength -= hairRemovedPerCut
    print(hairLength)