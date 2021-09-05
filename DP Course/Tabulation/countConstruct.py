def countConstruct(target: str, wordBank:list[str]) -> int:
	dp = [1] + [0] * len(target)
	for at in range(len(target) + 1):
		if dp[at] == 0:
			continue
		for word in wordBank:
			nextBit = target[at:at+len(word)]
			if word == nextBit:
				dp[at + len(word)] += dp[at]

	return dp[-1]

print(countConstruct("purple", ["purp", "p", "ur", "le", "purpl"])) # 2
print(countConstruct("abcdef", ["ab", "abc", "cd", "def", "abcd"])) # 1
print(countConstruct("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o", "t"])) #4