from numpy import diff
from itertools import accumulate

deskNum, studentNum = list(map(int, input().split(" ")))
studentDesks = list(map(int, input().split(" ")))

diffA = list(diff(studentDesks))

while len(studentDesks) > studentNum:
	lowestIndex = sorted(range(len(diffA)), key = lambda sub: diffA[sub])[0]
	studentDesks.pop(lowestIndex)
	diffA = list(diff(studentDesks))

print('output',min(diffA))