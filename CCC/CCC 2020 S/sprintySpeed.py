datas = int(input())
obs = []
for i in range(datas):
	toAdd = input().split(" ")
	for i in range(len(toAdd)):
		toAdd[i] = int(toAdd[i])
	obs.append(toAdd)

obs.sort()

highSpeed = 0
for index in range(len(obs)-1):
	distanceChange = abs(obs[index + 1][1] - obs[index][1])
	timeChange = abs(obs[index + 1][0] - obs[index][0])
	speed = distanceChange/timeChange
	if speed > highSpeed:
		highSpeed = speed

print(highSpeed)