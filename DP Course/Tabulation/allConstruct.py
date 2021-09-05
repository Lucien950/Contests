from typing import Union


def allConstruct(target: str, wordBank:list[str])->list[list[str]]:
	dp: Union[list[list[list[str]]], list[None]] = [[[]]] + [[] for i in range(len(target))]
	for at in range(len(target) + 1):
		# check reachable
		if len(dp[at]) == 0:
			continue
		for word in wordBank:
			nextBit = target[at:at+len(word)]
			if word == nextBit:

				for ways in dp[at]:
					dp[at+len(word)].append(ways + [word])
	return dp[-1]

print("\n".join([str(i) for i in allConstruct("purple", ["purp", "p", "ur", "le", "purpl"])]))
print("\n".join([str(i) for i in allConstruct("abcdef", ["ab", "abc", "cd", "def", "abcd"])]))
print("\n".join([str(i) for i in allConstruct("enterapotentpot", ["a", "p", "ent", "enter", "ot", "o", "t"])]))