cases = int(input());
for caseNum in range(cases):
	simRunTime = int(input())
	partyNum = int(input())
	hartalIntervals = []
	for partyIndex in range(partyNum):
		hartalIntervals.append(int(input()))
	
	days = [0]*simRunTime
	#Incriment days with hartals
	for hartalInterval in hartalIntervals:
		for day in range(hartalInterval-1, simRunTime, hartalInterval):
			days[day] += 1
	
	totalHartals = 0
	for dayNum in range(len(days)):
		if dayNum%4==0 or dayNum%5==0:
			continue
		if days[dayNum] > 0:
			totalHartals += 1
	
	print(totalHartals)
	print(days)