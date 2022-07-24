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

def mergeCrack(diffArr, diffCount):
    if len(diffCount) == 1:
        return "YES"
    pass

def solve():
    global differenceArr, diffCounter
    if len(differenceArr) <= 2:
        return "YES"
    secondMostCommon, secondCommonOccurance = diffCounter.most_common(2)[-1]
    if len(diffCounter.keys()) == 2 and secondMostCommon in (differenceArr[0], differenceArr[-1]):
        return "YES"
    
    return mergeCrack(differenceArr, diffCounter)

print(solve())