from collections import Counter
finalValue = int(input())

final = Counter()
for coin in [200, 100, 50, 20, 10, 5, 2, 1]:
    if finalValue == 0:
        break
    toMove = (finalValue//coin)
    final[coin] = toMove
    finalValue -= toMove *coin

list = []
[[list.append(i) for j in range(final[i])] for i in final if i != 0]
print(' '.join(map(str, list)))
print(len(list))