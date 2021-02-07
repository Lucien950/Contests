from collections import Counter
itemCount, limit = map(int, input().split())
items = list(map(int, input().split()))
yeet = Counter(items)

bags = 0
while items:
    item = items.pop()
    yeet[item] -= 1
    if item > limit:
        raise Exception("PENIS")
    for other in range(limit-item, 0, -1):
        if yeet[other]:
            yeet[other] -= 1
            items.remove(other)
            break
    bags += 1

print(bags)