from collections import defaultdict
sizeEnum = {'S': 0, 'M': 1, 'L': 2, '':4}
jerseyCount = int(input())
athleteCount = int(input())
jerseyList = [input() for _ in range(jerseyCount)]
athleteSizes = defaultdict(str)
for _ in range(athleteCount):
	size, number = input().split()
	number = int(number)
	if sizeEnum[size] < sizeEnum[athleteSizes[number]]:
		athleteSizes[number] = size

fulfilled = 0
for athleteNumber in athleteSizes:
	lookingForSize = athleteSizes[athleteNumber]
	largestJersey = jerseyList[sizeEnum[lookingForSize]-1]
	if sizeEnum[largestJersey] >= sizeEnum[lookingForSize]:
		fulfilled += 1
print(fulfilled)