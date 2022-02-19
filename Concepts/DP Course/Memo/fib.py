fibs = {}
def fib(n):
	if n <= 2:
		return 1
	if n not in fibs:
		fibs[n] = fib(n-1) + fib(n-2)
	return fibs[n]

print(fib(200))