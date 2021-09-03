length = int(input("How many digits?"))
fib = [0, 1] + [0] * (length-2)
for i in range(1, length):
	addNum = fib[i]
	for j in range(i + 1, i + 3):
		if j < len(fib):
			fib[j] += addNum
print(fib, len(fib))

# OR
fib = [0, 1, 1]
for i in range(length-3):
	fib.append(fib[-1] + fib[-2])
print(fib, len(fib))