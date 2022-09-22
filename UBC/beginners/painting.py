from collections import defaultdict

def oldSolve():
	global canvas, brushCount, brushes
	# precompute where brushes can be applied to canvas
	brushSpotsDict = defaultdict(list)
	for brush in brushes:
		for startIndex in range(len(canvas) - len(brush) + 1):
			if canvas[startIndex:startIndex + len(brush)] == brush:
				brushSpotsDict[brush].append(startIndex)

	# this code assumes that the first discovery of a fully painted canvas is the quickest way to fully paint it
	explored = set()
	toExplore = [("_" * len(canvas), 0, [])]
	finishPainted = False
	while toExplore and not finishPainted:
		painted, turns, moves = toExplore.pop(0)

		# apply paint
		for brushIndex, brush in enumerate(brushes):
			brushSpots = brushSpotsDict[brush]
			for brushSpot in brushSpots:
				newPainted = painted
				newPainted = newPainted[:brushSpot] + "*" * len(brush) + newPainted[brushSpot + len(brush): ]
				if newPainted == "*" * len(canvas):
					print(turns + 1)
					print("\n".join([" ".join(map(str, i)) for i in moves + [(brushIndex + 1, brushSpot + 1)]]))
					finishPainted = True
					break
				if newPainted not in explored:
					toExplore.append((newPainted, turns + 1, moves + [(brushIndex + 1, brushSpot + 1)]))
					explored.add(newPainted)
			if finishPainted:
				break
	
	if not finishPainted:
		print(-1)

cases = int(input())
for caseNum in range(cases):
	canvas = input()
	brushCount = int(input())
	brushes = [input() for _ in range(brushCount)]
	maxBrushLength = max(map(len, brushes))

	placable = [[] for _ in range(len(canvas))]
	for startIndex in range(len(canvas)):
		for brushNum, brush in enumerate(brushes):
			if startIndex + len(brush) <= len(canvas) and canvas[startIndex: startIndex + len(brush)] == brush:
				placable[startIndex].append(brushNum)
	
	firstUnfilled = 0
	dp = [(-1, float('inf')) for _ in range(len(canvas))]
	for brushIndex in placable[0]:
		dp[len(brushes[brushIndex])] = (brushIndex + 1, 1, -1)
	
	ans = None
	for firstUnfilled in range(len(canvas)):
		if dp[firstUnfilled][0] == -1:
			continue
		for startBrush in range(max(0, firstUnfilled - maxBrushLength), firstUnfilled + 1): # to cover the current one
			for nextBrushIndex, nextBrush in zip(placable[startBrush], map(lambda x: brushes[x], placable[startBrush])):
				endLocation = startBrush + len(nextBrush)
				if endLocation == len(canvas):
					# finished, assume quickest to end is the shortest
					ans = (nextBrushIndex + 1, dp[firstUnfilled][1] + 1, firstUnfilled)
					break
				if endLocation > firstUnfilled:
					dp[endLocation] = min(dp[endLocation], (nextBrushIndex + 1, dp[firstUnfilled][1] + 1, firstUnfilled), key=lambda x:x[1])

			if ans:
				break
		if ans:
			break
	
	if ans:
		print(ans[1])
		out = [f"{ans[0]} {ans[2]}"]
		atNode = ans[2]
		while dp[atNode][2] != -1:
			addOut = (dp[atNode][0], dp[atNode][2])
			out.append(" ".join(map(str, addOut)))
			atNode = dp[atNode][2]
		
		addOut = (dp[atNode][0], 1)
		out.append(" ".join(map(str, addOut)))
		print("\n".join(out))
	else:
		print(-1)