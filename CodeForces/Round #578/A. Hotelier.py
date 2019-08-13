w = input()
events = list(input())

rooms = [0,0,0,0,0,0,0,0,0,0] #Ten Rooms

def leftest(a):
    for i in range(10):
        if a[i] == 0:
            return i
    raise Exception("No Rooms available")
def rightest(a):
    for i in range(9, 0, -1):
        if a[i] == 0:
            return i
    raise Exception("No Rooms available")

for i in events:
    if type(i) is int:
        rooms[i] = 0
        continue
    elif i == "L":
        rN = leftest(rooms)
    elif i == "R":
        rN = rightest(rooms)
    rooms[rN] = 1


print(rooms)