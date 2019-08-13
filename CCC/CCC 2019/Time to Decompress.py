amount = int(input())
code = []
for i in range(amount):
    add = input().split()
    if len(add) != 2:
        raise Exception("Not Enough Chars")
    code.append([int(add[0]),add[1]])

for item in code:
    printer = ""
    for i in range(item[0]):
        printer += str(item[1])
    print(printer)