def numberToBase(n, b):
    if n == 0:
        return [0]
    digits = []
    while n:
        digits.append(int(n % b))
        n //= b
    return digits[::-1]
startYear, endYear = map(int, input().split())
base4 = int("".join(reversed(input().split())), base=4)
base4 += endYear

print(" ".join(reversed(list(map(str, numberToBase(base4, 4))))))