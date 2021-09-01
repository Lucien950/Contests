def monkeyWord(word):
	if len(word) == 0:
		return True

	if word[0] == "A":
		if len(word) > 1:
			if word[1] == "N":
				return monkeyWord(word[2:])
			# if there's more letters without separation by N
			else:
				return False
		else:
			# Just a
			return True
	elif word[0] == "B":
		try:
			# find the matching S
			si = 0
			bracketCounter = 1
			while bracketCounter > 0:
				si += 1
				if si >= len(word):
					si = -1
					break
				if word[si] == "B":
					bracketCounter += 1
				elif word[si] == "S":
					bracketCounter -= 1

			if si == 1 or si == -1:
				# BS not valid or "s" was not found
				return False
			if len(word) > si + 1:
				if word[si + 1] == "N":
					return monkeyWord(word[si + 2:]) and monkeyWord(word[1:si])
				else:
					return False
			else:
				return monkeyWord(word[1:si])
		except ValueError:
			return False
	return False

while True:
	x = input()
	if x == "X":
		break
	if not x:
		print("NO")
		continue

	print("YES" if monkeyWord(x) else "NO")