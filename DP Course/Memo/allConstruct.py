from copy import deepcopy
def allConstruct(target:str, wordBank:list[str], dp = None) -> list[list[str]]:
	if dp is None:
		if target == "":
			return [[]]
		dp = {}

	if target == "":
		return [[]]
	if target in dp:
		return deepcopy(dp[target])

	total = []
	for word in wordBank:
		if word in target and target.index(word) == 0:
			res = allConstruct(target[len(word):], wordBank, dp)
			for element in res:
				element.append(word)
				total.append(deepcopy(element))

	dp[target] = deepcopy(total)
	return total

print(allConstruct("banana", ["ba", "pa", "ca", "na"])) # 1
print(allConstruct("", ["ba", "pa", "ca", "na"])) # 0
print(allConstruct("abcdef", ["ab", "abcdefgh", "c", "def"])) # 1
print(allConstruct("potato", ["pot", "ta", "to"])) # 0
print(allConstruct("skateboard", ["skat", "te", "bor", "ard"])) # 0
print(allConstruct("skateboard", ["skat", "te", 'e', "bo", "ard", 'ska'])) # 2
print(allConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", [
    'e',
    'ee',
    'eee',
    'eeee',
    'eeeee',
    'eeeeee',
    'eeeeeee',
    'eeeeeeee'
])) # 0