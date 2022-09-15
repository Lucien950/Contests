import itertools


cases = int(input())

def timeDiff(startTime, endTime):
	# startHour, startMin | endHour, endMin
	startHour, startMin = startTime
	endHour, endMin = endTime
	diffMin = (endMin - startMin) % 60
	diffHour = (endHour - startHour - (1 if endMin < startMin else 0)) % 24
	return (diffHour, diffMin)


for caseNum in range(cases):
	alarmCount, startHour, startMin = map(int, input().split())
	alarms = [tuple(map(int, input().split())) for _ in range(alarmCount)]
	time = min(map(timeDiff, itertools.repeat((startHour, startMin)), alarms))
	print(" ".join(map(str, time)))