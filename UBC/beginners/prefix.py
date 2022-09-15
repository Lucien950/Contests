cases = int(input())
for caseNum in range(cases):
	caseLength = int(input())
	case = list(map(int, input().split()))
	
	suffix = set()	
	for startIndex in range(caseLength - 1, -1, -1):
		if case[startIndex] in suffix:
			startIndex += 1
			break
		suffix.add(case[startIndex])
	print(startIndex)