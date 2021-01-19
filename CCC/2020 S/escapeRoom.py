#Imports
import math

#9 returns [(0, 8), (8, 0), (2, 2)]
def factorize(num):
	returnList = []
	for i in range(1,math.floor(math.sqrt(num))+1):
		if num%i == 0:
			otherI = int(num/i)
			returnList.append((i-1, otherI-1))
			if i != otherI:
				returnList.append((otherI-1, i-1))
	return returnList
def finish(bool):
	if bool:
		print("yes")
		quit()
	else:
		print("no")

#======================INPUT HANDLING======================
row = int(input())
col = int(input())

room = []
for i in range(row):
	toAdd = input().split(" ")
	for j in range(len(toAdd)):
		toAdd[j] = int(toAdd[j])
	room.append(toAdd)

#======================Processing======================
finishRow = row-1
finishCol = col-1


def fill(packet):
	pRow = packet[0]
	pCol = packet[1]
	lookValue = ((pRow + 1) * (pCol + 1))
	lookIndicies = []
	#Fill in lookIndicies
	for rowNum in range(row):
		for colNum in range(col):
			if room[rowNum][colNum] == lookValue:
				lookIndicies.append((rowNum, colNum))

	for location in lookIndicies:
		(newRow, newCol) = location
		if [newRow, newCol] in explored:#Already Explored
			continue
		if [newRow, newCol] == [0,0]:
			return True
		toExplore.append([newRow, newCol])
		explored.append([newRow, newCol])

toExplore = [
	[finishRow, finishCol]
]
explored = [
	[finishRow, finishCol]
]
while len(toExplore) != 0:
		if fill(toExplore.pop(0)):
			finish(True)
finish(False)