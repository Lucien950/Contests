datas = int(input())
obs = [tuple(map(int, input().split())) for _ in range(datas)]
obs.sort()

highSpeed = 0
for i in range(1, datas):
	lastTime, lastPos = obs[i-1]
	curTime, curPos = obs[i]
	speed = abs(curPos - lastPos) / (curTime - lastTime)
	highSpeed = max(highSpeed, speed)

print(highSpeed)