def canConstruct(target: str, wordBank: list[str])->bool:
	dp:list[bool] = [True] + [False] * len(target)
	for at in range(len(target) + 1):
		# check reachable
		if not dp[at]:
			continue
		for word in wordBank:
			nextBit = target[at:at+len(word)]
			if word == nextBit:
				dp[at+len(word)] = True

	print(dp)
	return dp[-1]

print(canConstruct("abcdef", ["ab", "abc", "cd", "def", "abcd"]))