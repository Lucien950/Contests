# roman letters to numbers
def roman(letter):
    if letter == 'I':
        return 1
    elif letter == 'V':
        return 5
    elif letter == 'X':
        return 10
    elif letter == 'L':
        return 50
    elif letter == 'C':
        return 100
    elif letter == 'D':
        return 500
    elif letter == 'M':
        return 1000

number = input()
total = 0
# split number into groups of two
pairs = [number[i:i+2] for i in range(0, len(number), 2)]
for i, pair in enumerate(pairs):
    romanPart = roman(pair[1])
    val = int(pair[0]) * romanPart

    if i == len(pairs) - 1 or romanPart >= roman(pairs[i+1][1]): total += val
    else: total -= val

print(total)