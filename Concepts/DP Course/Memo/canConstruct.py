badTargets = set()
def canConstruct(target: str, wordBank: list[str])->bool:
	if len(target) == 0:
		return True
	if target in badTargets:
		return False
	for word in wordBank:
		index = target.index(word) if word in target else -1
		if index == 0:
			if canConstruct(target[len(word):], wordBank):
				return True
	badTargets.add(target)
	return False

print(canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", ["e", "ee", "eee", "eeee", "eeeee", "eeeeeef"]))