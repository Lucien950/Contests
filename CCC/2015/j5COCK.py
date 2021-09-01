pieCount = int(input())
peopleCount = int(input())


# badDP = {}
solutions = []
def mathHard(val, length, actual):
	# if (val, length, actual) in badDP:
	# 	print("use dp")
	# 	return badDP[(val, length, actual)]

	if val > pieCount:
		return 0
	if val == pieCount and length == peopleCount:
		solutions.append(actual)
		return 1
	leftSide = mathHard(val + 1, length + 1, "1" + actual) if length <= peopleCount else 0
	rightSide = mathHard(val + length, length, "".join(map(str, [int(i) + 1 for i in actual])))
	ans = leftSide + rightSide
	# badDP[(val, length, actual)] = ans
	return ans

	# if length == peopleCount:
	# 	if val == pieCount:
	# 		# print(actual)
	# 		total += 1
	# 		continue
	# else:
	# 	# make longer
	# 	fucks.append((val + 1, length + 1, "1" + actual))
	#
	# if val > pieCount:
	# 	return 0
	#
	# # add one to everything
	# fucks.append((val + length, length, "".join(map(str, [int(i) + 1 for i in actual]))))

print(mathHard(1, 1, "1"))
print("\n".join(solutions))
