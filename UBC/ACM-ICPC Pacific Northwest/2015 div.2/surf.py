class Wave:
	def __init__(self, data) -> None:
		self.startTime = data[0]
		self.points = data[1]
		self.endTime = self.startTime + data[2]
	def __repr__(self) -> str:
		return f"{self.startTime} - {self.endTime} for {self.points} points"

def new(waves: list[Wave]):
	dp = [-1 for _ in range(waves[-1].endTime + 1)]
	dp[0] = 0
	waveArrayPointer = 0
	for timeAt in range(1, len(dp)):
		waveAt = waves[waveArrayPointer]
		if waveAt.endTime == timeAt:
			while waveAt.endTime == timeAt:
				dp[timeAt] = max(dp[timeAt], dp[timeAt - 1], dp[waveAt.startTime] + waveAt.points)
				waveArrayPointer += 1
				if waveArrayPointer >= len(waves):
					break
				waveAt = waves[waveArrayPointer]
		else: dp[timeAt] = dp[timeAt - 1]
	return dp[-1]

waveCount = int(input())
waves = sorted([Wave(tuple(map(int, input().split()))) for _ in range(waveCount)], key=lambda x: x.endTime)
print(new(waves))

# TESTER
# def searchDP():
# 	dp = defaultdict(int)
# 	dp[0] = 0
# 	for wave in waves:
# 		# find the largest points dp[t] where t < startTime\
# 		# [time, points]
# 		search = sorted(list(dp.items()))
# 		l, r = 0, len(dp)
# 		while l < r:
# 			mid = (l + r)//2
# 			if search[mid][0] >= wave.startTime:
# 				r = mid
# 			else:
# 				l = mid+1
		
# 		points = (search[l-1][1] + wave.points)
# 		dp[wave.endTime] = max(dp[wave.endTime], points)
# def works(waves: list[Wave]):
# 	dp = [0 for _ in range(waves[-1].endTime + 1)]
# 	for wave in waves:
# 		points = (dp[wave.startTime] + wave.points)
# 		for i in range(wave.endTime, len(dp)):
# 			if points <= dp[i]:
# 				break
# 			dp[i] = points
# 	return dp[-1]
# while True:
# 	waveCount = 5
# 	waves: list[Wave] = []
# 	for _ in range(waveCount):
# 		startTime, points = randint(0, 30), randint(0, 30)
# 		duration = randint(1, 31 - startTime)
# 		waves.append(Wave((startTime, points, duration)))
# 	waves.sort(key=lambda x: x.endTime)
# 	a, b = new(waves), works(waves)
# 	if a != b:
# 		print(waveCount)
# 		print("\n".join([" ".join(map(str, [wave.startTime, wave.points, wave.endTime - wave.startTime])) for wave in waves]))
# 		break