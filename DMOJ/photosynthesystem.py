# This one: https://dmoj.ca/problem/ecoo18r2p1


for setNum in range(10):
	carbon, oxygen, water, sugar = map(int, input().split())
	# plant reaction
	c1, w1, s1, o1 = map(int, input().split())
	#fish reaction
	s2, o2, c2, w2 = map(int, input().split())

	def enoughPhoto(): return carbon >= c1 and water >= w1
	def enoughRespire(): return sugar >= s2 and oxygen >= o2
	def photo():
		global carbon, water, sugar, oxygen
		carbon -= c1
		water -= w1
		sugar += s1
		oxygen += o1
	def respire():
		global carbon, water, sugar, oxygen
		sugar -= s2
		oxygen -= o2
		carbon += c2
		water += w2

	#photosynthesise as hard as you can
	while enoughPhoto():
		photo()

	#keep respiring
	#I think there should be an optimization to break early, but I'm to lazy to find it
	#Open up a pull request if you're into it 🙏
	state = {"carbon": carbon, "oxygen": oxygen, "water": water, "sugar": sugar}
	while enoughRespire():
		respire()
		if enoughPhoto():
			photo()
			if oxygen > state["oxygen"]:
				state = {"carbon": carbon, "oxygen": oxygen, "water": water, "sugar": sugar}

	carbon = state["carbon"]
	oxygen = state["oxygen"]
	water = state["water"]
	sugar = state["sugar"]

	# FINAL ANSWER
	# print(f"carbon {carbon}, water {water}, sugar {sugar}, oxygen {oxygen}")
	print(oxygen)