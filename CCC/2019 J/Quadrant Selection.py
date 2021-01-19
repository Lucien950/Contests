p1 = int(input())
p2 = int(input())

if p1 >= 0 and p2 >= 0:
    print("1")
elif p1 < 0 and p2 >= 0:
    print("2")
elif p1 >= 0 and p2 < 0:
    print("4")
else:
    print("3")