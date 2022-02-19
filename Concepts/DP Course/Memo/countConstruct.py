def countConstruct(target: str, wordBank: list[str], dp = None) -> int:
	if dp is None:
		if target == "":
			return 0
		dp = {}
	# base cases
	if target == "":
		return 1
	if target in dp:
		return dp[target]

	total = 0
	for word in wordBank:
		if word in target and target.index(word) == 0:
			total += countConstruct(target[len(word):], wordBank, dp)

	dp[target] = total
	return dp[target]

print(countConstruct("banana", ["ba", "pa", "ca", "na"])) # 1
print(countConstruct("", ["ba", "pa", "ca", "na"])) # 0
print(countConstruct("abcdef", ["ab", "abcdefgh", "c", "def"])) # 1
print(countConstruct("potato", ["pot", "ta", "to"])) # 0
print(countConstruct("skateboard", ["skat", "te", "bor", "ard"])) # 0
print(countConstruct("skateboard", ["skat", "te", 'e', "bo", "ard", 'ska'])) # 2
print(countConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", [
    'e',
    'ee',
    'eee',
    'eeee',
    'eeeee',
    'eeeeee',
    'eeeeeee',
    'eeeeeeee'
])) # 0