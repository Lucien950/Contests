apples = []
for i in range(3):
    apples.append(int(input())*(3-i))
bananas = []
for i in range(3):
    bananas.append(int(input())*(3-i))

appScore = sum(apples)
banScore = sum(bananas)

if appScore > banScore:
    print('A')
elif appScore < banScore:
    print('B')
else:
    print('T')