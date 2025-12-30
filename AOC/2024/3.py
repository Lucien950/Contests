import re

lines = open("3.in").readlines()

out = 0
line = "".join([l.strip() for l in lines])
enabled = True
for instruction in re.finditer(r'mul\((\d{1,3}),(\d{1,3})\)|do\(\)|don\'t\(\)', line.strip()):
	if instruction.group() == "do()":
		enabled = True
	elif instruction.group() == "don't()":
		enabled = False
	else:
		if enabled:
			a, b = map(int, instruction.groups())
			out += a * b
print(out)