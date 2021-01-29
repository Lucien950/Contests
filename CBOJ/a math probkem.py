a, b = tuple(map(int, input().split()))

def ans():
    for x in range(101):
        for y in range(x, 1001):
            for z in range(y, 1001):
                a1, b1 = (x * y * z, x**2 + y**2 + z**2)
                if a1 == a and b1 == b:
                    print(x, y, z)
                    return
                if a1 > a or b1 > b:
                    break
    print(-1)

ans()