n = int(input())
c = input()
c = c.split(" ")
temp = []
for i in c:
    temp.append(int(i))
c = temp

if len(c) != n:
    raise Exception("Input Problems")

if sum(c) <= 200:
    print(200-sum(c))
else:
    print("Over maximum capacity!")