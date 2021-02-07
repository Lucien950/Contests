from collections import Counter
a = input()
b = input()

a = Counter(a)
b = Counter(b)

def solve():
    wildCards = b['*']
    for element in a:
        if a[element] != b[element]:
            if wildCards > 0:
                wildCards -= a[element] - b[element]
            else:
                print("N")
                return
    print("A")

solve()