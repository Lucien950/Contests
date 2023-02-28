class Blade:
	def __init__(self, bladeStart, bladeTime) -> None:
		self.bladeStart = bladeStart
		self.bladeTime = bladeTime

def timeTo(fro, to, hl):
	return -log2(to / fro) * hl

from math import log2
from collections import defaultdict
start, target, bladeCount = map(int, input().split())

blades = defaultdict(lambda: float('inf'))
for _ in range(bladeCount):
	bladeStart, bladeTime = map(int, input().split())
	blades[bladeStart] = min(blades[bladeStart], bladeTime)

if not any([k >= start for k in blades.keys()]):
	print(-1)
else:
	bladeList = list(map(lambda x: Blade(*x), blades.items()))
	bladeList.sort(reverse=True, key=lambda x: x.bladeStart)
	
	time = 0
	useBlade = bladeList[0]
	for blade in bladeList:
		if target > blade.bladeStart: break
		if blade.bladeTime < useBlade.bladeTime:
			if start > blade.bladeStart:
				time += timeTo(min(useBlade.bladeStart, start), blade.bladeStart, useBlade.bladeTime)
			useBlade = blade
	
	time += timeTo(min(useBlade.bladeStart, start), target, useBlade.bladeTime)
	
	print(time)