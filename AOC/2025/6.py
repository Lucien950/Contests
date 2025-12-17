from functools import reduce
from operator import mul,add

lines = open("6.in", "r").readlines()


num_lines = lines[:-1]
op_line = lines[-1]

out = 0

op = None
result = 0
for col in range(len(num_lines[0])):
	if op == None:
		if op_line[col] == '*':
			op = mul
			result = 1
		elif op_line[col] == '+':
			op = add
			result = 0
		else:
			raise ValueError("Unknown operator")
	
	at_num_str = "".join([num_lines[i][col].strip() if num_lines[i][col] != ' ' else '' for i in range(len(num_lines))])
	if len(at_num_str) == 0:
		# reset
		out += result
		op = None
		continue

	result = op(result, int(at_num_str))
	
print(out)