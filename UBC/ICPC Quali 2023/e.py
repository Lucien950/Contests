s = input()
vowels = ["a", "e", "i", "o", "u"]

c, nc = 0, 0
for ch in s:
    if ch in vowels:
        nc += 1
        c += 1
    elif ch == "y":
        nc += 1
print(c, nc)
