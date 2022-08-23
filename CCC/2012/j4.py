import string

alphaKey = list(string.ascii_uppercase)
letterIndex = {l:i for i, l in enumerate(list(string.ascii_uppercase))}
k = int(input())
string = input()
out = ""
for i, letter in enumerate(string):
    S = 3*(i + 1) + k
    letterI = letterIndex[letter]
    originalLetterIndex = letterI - S + 1
    if originalLetterIndex <= 0:
        originalLetterIndex += 26
    out += alphaKey[originalLetterIndex - 1]

print(out)