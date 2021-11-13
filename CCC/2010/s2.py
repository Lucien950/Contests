from collections import defaultdict
dict = defaultdict(int)
for i in range(int(input())):
    letter,code = input().split()
    dict[code] = letter
code = input()
out = ""
letterStack = ""
for i in code:
    letterStack += i
    if letterStack in dict:
        out += dict[letterStack]
        letterStack = ""
print(out)