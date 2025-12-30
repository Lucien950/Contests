import re
from typing import Counter


lines = open('4.in').readlines()

out = 0
# for row in lines:
# 	out += len(re.findall('XMAS', row))
# 	out += len(re.findall('SAMX', row))
# for col in zip(*lines):
# 	col = "".join(col)
# 	out += len(re.findall('XMAS', col))
# 	out += len(re.findall('SAMX', col))
# for x0 in range(len(lines)-3):
# 	for y0 in range(len(lines[0])-3):
# 		diag = ''.join(lines[x0+i][y0+i] for i in range(4))
# 		out += diag == "XMAS" or diag == "SAMX"
# for x0 in range(3, len(lines)):
# 	for y0 in range(len(lines[0])-3):
# 		diag = ''.join(lines[x0-i][y0+i] for i in range(4))
# 		out += diag == "XMAS" or diag == "SAMX"

for row in range(len(lines)):
	for col in range(len(lines[0])):
		if lines[row][col] != 'A': continue
		if not 1 <= row < len(lines) - 1:
			continue
		if not 1 <= col < len(lines[0]) - 1:
			continue
		l = [
			lines[row-1][col-1],
			lines[row+1][col-1],
			lines[row-1][col+1],
			lines[row+1][col+1]
		]
		if Counter(l) != {"M": 2, "S": 2}: continue
		if l == ["M", "S", "S", "M"] or l == ["S", "M", "M", "S"]: continue
		out += 1

print(out)