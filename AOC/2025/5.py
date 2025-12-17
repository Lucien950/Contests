fresh_ranages: list[tuple[int, int]] = []
def fresh_find(a: int) -> int:
	"""
	return index of the range who starts to the left of a

	fresh = [] a = 2 -> -1
	fresh = [(1,3), (5,7)] a = 0 -> -1
	fresh = [(1,3), (5,7)] a = 1 -> 0
	fresh = [(1,3), (5,7)] a = 2 -> 0
	fresh = [(1,3), (5,7)] a = 4 -> 0
	fresh = [(1,3), (5,7)] a = 5 -> 1
	fresh = [(1,3), (5,7)] a = 10 -> 1
	"""
	l, r = 0, len(fresh_ranages) - 1
	while l <= r:
		mid = (l + r) // 2
		if fresh_ranages[mid][0] <= a:
			l = mid + 1
		else:
			r = mid - 1
	return r

def fresh_join(a: int, b: int) -> None:
	global fresh_ranages
	at: int = fresh_find(a)
	if len(fresh_ranages) == 0:
		fresh_ranages.append((a,b))
		return

	if at == -1:
		fresh_ranages.insert(0, (a,b))
		at = 0
	else:
		i, j = fresh_ranages[at]
		if j < a - 1:
			# no overlap, insert after
			fresh_ranages.insert(at + 1, (a,b))
			at += 1
		else:
			assert i <= a, f"{at}: {i}-{j} vs {a}-{b}"
			fresh_ranages[at] = (min(i,a), max(j,b))

	# now try to merge forward
	while at + 1 < len(fresh_ranages):
		ni, nj = fresh_ranages[at + 1]
		i, j = fresh_ranages[at]
		if ni > j + 1:
			break
		fresh_ranages[at] = (i, max(j, nj))
		del fresh_ranages[at + 1]
	
out = 0
for l in open("5.in", "r").readlines():
	l = l.strip()
	if '-' in l:
		a,b = map(int, l.split('-'))
		fresh_join(a,b)
	elif len(l) == 0:
		continue
	else:
		q = int(l)
		idx = fresh_find(q)
		if idx == -1:
			continue
		i, j = fresh_ranages[idx]
		if i <= q <= j:
			out += 1
print(f"part 1: {out}")


out2 = 0
for a,b in fresh_ranages:
	out2 += b - a + 1
print(f"part 2: {out2}")