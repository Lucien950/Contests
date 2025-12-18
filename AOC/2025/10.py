from functools import reduce
from operator import or_
import numpy as np
import cvxpy as cp

lines = open("10.in").readlines()

def to_n(lst: list[int], button_count) -> np.ndarray:
	"""
	convert list of indices to tuple representation
	"""
	out = [0 for _ in range(button_count)]
	for i in lst: out[i] = 1
	return np.array(out).T

out = 0
for line in lines:
	line = line.strip().split()
	final_str, buttons_str, jolts_str = line[0], line[1:-1], line[-1]
	button_count = len(final_str) - 2
	b = np.array([int(j) for j in jolts_str[1:-1].split(",")])
	buttons_pre: list[list[int]]= [[int(b) for b in button[1:-1].split(",")] for button in buttons_str]
	A = np.vstack([to_n(button, button_count) for button in buttons_pre]).T
	# least squares solution to A * x = b on the integers
	x = cp.Variable(A.shape[1], integer=True)
	objective = cp.Minimize(cp.sum(x))
	constraints = [A @ x == b, x >= 0] 
	prob = cp.Problem(objective, constraints)
	prob.solve(solver=cp.ECOS_BB)
	if prob.status == cp.OPTIMAL and x.value is not None:
		out += int(sum(round(v) for v in x.value))
	else:
		raise ValueError("No optimal solution found")

print(out)