numbers = list(map(int, input().split(" ")))

found = False
for i in range(1, 6):
	if found:
		break
	for j in range(1,i):
		# The idea here is that you find the group with the first element
		if 2 * (numbers[0] + numbers[i] + numbers[j]) ==  sum(numbers):
			found=True
			break

print("YES") if found else print("NO")