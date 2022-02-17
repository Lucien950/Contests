# import random
# import string
# data = ["".join([random.choice(string.ascii_letters) for _ in range(10000)]), "".join([random.choice(string.ascii_letters) for _ in range(200000)])]
# input = lambda : data.pop(0)

# Fuck DMOJ memory limits cause penis
from sys import stdin
input = stdin.readline

from collections import Counter
needle = input().rstrip()
hay = input().rstrip()

def count_needle(needle, hay):
	lenNeedle = len(needle)
	if lenNeedle > len(hay): return 0
	counterNeedle = Counter(needle)
	activeCounter = Counter(hay[0:lenNeedle-1])
	perms = set()
	# needleLetters = set(needle)

	startI = 0
	while startI <= len(hay) - lenNeedle:
		# add new letter to active counter
		# if hay[startI + lenNeedle-1] not in needleLetters:
		# 	startI += lenNeedle
		# 	continue
		activeCounter[hay[startI + lenNeedle-1]] += 1

		# check if there is a new permutation
		activeNeedle = hay[startI:startI + lenNeedle]
		if counterNeedle == activeCounter and activeNeedle not in perms:
			perms.add(activeNeedle)
		del activeNeedle
		
		# remove the first element from counter
		activeCounter[hay[startI]] -= 1
		if activeCounter[hay[startI]] == 0:
			del activeCounter[hay[startI]]
		
		# loop go brrr
		startI += 1
	
	return len(perms)

print(count_needle(needle, hay))