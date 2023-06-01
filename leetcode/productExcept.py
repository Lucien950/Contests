def productExceptSelf(nums):
	res = [1] * len(nums)
	l = 1
	for i, num in enumerate(nums):
		res[i] *= l
		l *= num
	l = 1
	for i, num in reversed(list(enumerate(nums))):
		res[i] *= l
		l *= num
	return res

v = productExceptSelf([1,2,3,4])
print(v)