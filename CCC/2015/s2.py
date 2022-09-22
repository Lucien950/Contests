sizeEnum = {'S': 0, 'M': 1, 'L': 2}

jerseyCount = int(input())
requestCount = int(input())

jerseySizes = [sizeEnum[input()] for _ in range(jerseyCount)]
requests = [input().split() for _ in range(requestCount)]

smallestJerseyForNum = [float('inf') for _ in range(jerseyCount)]
for size, number in requests:
	size = sizeEnum[size]
	number = int(number) - 1
	smallestJerseyForNum[number] = min(size, smallestJerseyForNum[number])


fulfilled = 0
for jerseyNum in range(jerseyCount):
	if smallestJerseyForNum[jerseyNum] <= jerseySizes[jerseyNum]:
		fulfilled += 1
print(fulfilled)