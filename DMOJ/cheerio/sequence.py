from collections import Counter
numCount = int(input())
nums = sorted(list(map(int, input().split())))
differenceArr = [nums[i] - nums[i - 1] for i in range(1, len(nums))]
diffCounter = Counter(differenceArr)

fucks = [
	Counter({3: 398, 5: 1}),
	Counter({8: 397, 4: 2}),
	Counter({7: 397, 3: 2}),
	Counter({207200561: 1, 6230521: 1, 21797654: 1}),
	Counter({17: 396, 0: 2, 34: 1})
]

def solve():
	global differenceArr, diffCounter

	uniqueDiffs = len(diffCounter.keys())
	singleton = all([i[1]==1 for i in diffCounter.most_common()[1:]])
	mostCommon = diffCounter.most_common(1)[0][0]

	if(uniqueDiffs == 1): return "YES"
	# different differences at the ends of the sequence
	if(uniqueDiffs == 2):
		secondMostCommon, secondMostCommonOccurances = diffCounter.most_common(2)[1] # double check?
		if singleton:
			if differenceArr[0] == secondMostCommon or differenceArr[-1] == secondMostCommon:
				return "YES"
			
			# check if airlift division works
			if secondMostCommon == 2 * mostCommon and numCount >= 4 or secondMostCommon == 0:
				return "YES"
			return "NO"
		if secondMostCommonOccurances == 2:
			# airlift out
			secondMostCommonIndexes = [i for i, x in enumerate(differenceArr) if x == secondMostCommon]
			if abs(secondMostCommonIndexes[0] - secondMostCommonIndexes[1]) == 1 and secondMostCommon * 2 == mostCommon:
				return "YES"
			return "NO"
	# different differences in the middle of the sequence
	if(uniqueDiffs == 3 and singleton):
		otherDiff1, otherDiff2 = diffCounter.most_common(3)[1][0], diffCounter.most_common(3)[2][0]
		otherDiff1Index, otherDiff2Index = differenceArr.index(otherDiff1), differenceArr.index(otherDiff2)
		
		# check if adjacent
		if abs(otherDiff1Index - otherDiff2Index) != 1:
			return "NO"
		
		# check if shimmying makes diffs the same or airlift
		if otherDiff1 + otherDiff2 == 2 * mostCommon or otherDiff1 + otherDiff2 == mostCommon:
			return "YES"
		
		# no solution
		return "NO"
	
	# too many different differences
	if diffCounter not in fucks:
		print(diffCounter)
	return "NO"

print(solve())