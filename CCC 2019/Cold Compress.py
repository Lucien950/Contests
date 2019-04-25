amount = input()
strings = []
for i in range(int(amount)):
    strings.append(input())

out = []
for string in strings:
    toout = []
    count = 0
    for i in range(len(string)):
        if i == 0:
            count += 1
        elif string[i] == string[i-1]:
            count += 1
            if i+1 == len(string):
                toout.append([str(count), string[i]])
        else:
            toout.append([str(count), string[i-1]])
            count = 1
            if i+1 == len(string):
                toout.append(["1", string[i]])
    out.append(toout)

output = ""
for l in out:
    for duo in l:
        for item in duo:
            output += item
            output += " "
    print(output)
    output = ""