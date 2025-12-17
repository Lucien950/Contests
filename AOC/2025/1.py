a_file = open("1.in")
lines = a_file.readlines()

out = 0
at = 50
for line in lines:
	line = line.strip()
	direction, rots = line[0], int(line[1:])
	if direction == "L":
		next_raw = at - rots
		a = next_raw
		b = at - 1
	elif direction == "R":
		next_raw = at + rots
		a = at + 1
		b = next_raw
	else:
		raise Exception("Unknown direction")
	assert a <= b
	# counts multiples of 100 between a, b inclusive
	out += b // 100 - (a - 1)// 100
	at = next_raw % 100

print(out)