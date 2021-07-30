from collections import Counter
needle = input()
hay = input()

counterNeedle = Counter(needle)
lenNeedle = len(needle)

i = 0
permuations = []
activeCounter = Counter(hay[0:lenNeedle])
hayLen = len(hay)
for startI in range(len(hay) - lenNeedle + 1):
	if counterNeedle == activeCounter and hay[startI:startI + lenNeedle] not in permuations:
		i += 1
		permuations.append(hay[startI:startI + lenNeedle])

	activeCounter[hay[startI]] -= 1
	if activeCounter[hay[startI]] == 0:
		del activeCounter[hay[startI]]
	if startI + lenNeedle < hayLen:activeCounter[hay[startI + lenNeedle]] += 1

print(i)