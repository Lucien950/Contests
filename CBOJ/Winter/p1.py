ways = int(input())
list = input().split()

valids = set()
valids.add("".join(list))
for i in range(ways):
    list.append(list.pop(0))
    new = "".join(list)
    if new not in valids:
        valids.add(new)

print(len(valids))