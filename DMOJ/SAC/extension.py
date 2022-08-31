n = int(input())
direction = input()
opposite = {"left": "right", "right":"left"}
if n%2==0:
	print(opposite[direction])
else:
	print(direction)