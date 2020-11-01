import random
while true:
    list = []
    if random.uniform(0, 1) + random.uniform(0, 1) <= 1:
        list.append(1)
    else:
        list.append(0)
    print((sum(list)/len(list)))