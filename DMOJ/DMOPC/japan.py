cases = int(input())
ans = []
for caseNum in range(cases):
	text = input()
	vowels = ['a', 'e', 'i', 'o', 'u']
	consanants = ["k", "n", "h", "m", "r"]
	uConsanants = ["k", "n", "f", "m", "r"]
	prevCons = None
	ok = True
	for c in text:
		if c in vowels:
			if prevCons and ((c == "u" and prevCons not in uConsanants) or (c!= "u" and prevCons not in consanants)):
				ans.append("NO")
				ok = False
				break
			prevCons = None
		# if consonant
		elif prevCons != None:
			ans.append("NO")
			ok = False
			break
		else:
			prevCons = c
	
	if not ok:
		continue

	if text[-1] not in vowels:
		ans.append("NO")
		continue
	ans.append("YES")

print("\n".join(ans))