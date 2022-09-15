from collections import Counter
string = input()
needRid = max(len(set(string)) - 2, 0)
if needRid == 0:
	print(0)
else:
	leastCommons = Counter(string).most_common()[-needRid:]
	print(sum(map(lambda x: x[1], leastCommons)))