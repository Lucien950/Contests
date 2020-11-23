from itertools import permutations
inNum = list(input())

isDivisor = False

for i in permutations(inNum):
	num = ''.join(i)
	if num != str(int(num)):
		continue
	
	if int(num) % 4 == 0:
		isDivisor = True
		break

print("YES" if isDivisor else "NO")