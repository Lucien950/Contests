import sys
input = sys.stdin.readline
for caseNum in range(int(input())):
    a, b, c = map(int, input().split())

    # case 1
    b %= 2
    
    # case 2
    remove = min(a, b, c)
    a -= remove
    b -= remove
    c -= remove

    # case 3
    remove = min(a, c)
    a -= remove
    c -= remove

    # case 4
    remove = min(a//2, b)
    a -= remove*2
    b -= remove

    # case 5
    a %= 2

    print("YES") if a == 0 and b == 0 and c == 0 else print("NO")
