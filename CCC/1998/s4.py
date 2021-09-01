cases = int(input())

val = {
	"I": 1,
	"V": 5,
	"X":10,
	"L": 50,
	"C": 100,
	"D": 500,
	"M": 1000
}
modifiers = {
	"IV": 4,
	"IX": 9,
	"XL": 40,
	"XC": 90,
	"CD":400,
	"CM":900,
}
def roman(string):
	out = 0
	skip = False
	for i, c in enumerate(string):
		if skip:
			skip = False
			continue

		if i + 1 < len(string) and string[i:i+2] in modifiers:
			out += modifiers[string[i:i+2]]
			skip = True
		else:
			out += val[c]
	return out

piss = {v: k for k, v in val.items()}
piss.update({v: k for k, v in modifiers.items()})
piss = {k:v for k, v in sorted(piss.items(), key=lambda item: item[0], reverse=True)}
def toRoman(num):
	out = ""
	for val in piss:
		while num >= val:
			out += piss[val]
			num -= val
	return out


for i in range(cases):
	cock = input()
	a, b = cock[:-1].split("+")
	aInt, bInt = (roman(a), roman(b))

	sum = aInt + bInt
	if sum > 1000:
		print(cock+"CONCORDIA CUM VERITATE")
	else:
		print(cock+toRoman(sum))