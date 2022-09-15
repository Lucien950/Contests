cases = int(input())
for caseNum in range(cases):
	case = int(input())
	digits = []
	digitAt = 9
	sumDigits = 0
	while case - sumDigits > digitAt:
		digits.append(digitAt)
		sumDigits += digitAt
		digitAt -= 1
	digits.append(case - sumDigits)
	print("".join(map(str, reversed(digits))))