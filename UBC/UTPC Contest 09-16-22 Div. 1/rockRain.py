class Range:
	def __init__(self, rangeStart, rangeEnd) -> None:
		self.rangeStart = rangeStart
		self.rangeEnd = rangeEnd
		self.rangeSize = 1
	def __repr__(self) -> str:
		return f"{self.rangeStart}-{self.rangeEnd}"
	def recalculateSize(self):
		self.rangeSize = self.rangeEnd - self.rangeStart
rockCount, basketCount = map(int, input().split())
rockGroups: list[Range] = list(map(lambda x: Range(x, x), sorted(map(int, input().split()))))

gap = 1
while True:
	# check that we have a good basket size
	if len(rockGroups) <= basketCount:
		print(gap)
		break
	
	newRockGroups = []
	skip = False
	for i, rockGroup in enumerate(rockGroups):
		if skip:skip = False; continue
		if i < len(rockGroups) - 1 and rockGroups[i + 1].rangeEnd - rockGroup.rangeStart <= gap:
			newRockGroups.append(Range(rockGroup.rangeStart, rockGroups[i + 1].rangeEnd))
			skip = True
		else: newRockGroups.append(rockGroup)
	rockGroups = newRockGroups
		
	gap += 1