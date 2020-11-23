testCount, studyTime = list(map(int, input().split(" ")))
testDays = sorted(list(map(int, input().split(" "))))[::-1] # take input, split it, int it, make list, sort it, invert it
beforeDays = 0

for i in range(len(testDays)-1):
	j = i + 1
	late, early = testDays[i], testDays[j]
	beforeDays = max(beforeDays+(studyTime-(late-early)), 0)
	
# ACCOUNT FOR DAY 1
print(beforeDays+studyTime)