def solve(totalNoteCount, maxPitch, totalSamples):
	# if there are more notes than samples, even if you go 1 1 1...
	# there will be too many samples
	if totalSamples < totalNoteCount: return "-1"


	notesLeft, samplesLeft = totalNoteCount, totalSamples
	piece = [] 
	addBy, i = 1, 1
	# leave when cannot add full batch or need to save notes to reach end
	while addBy <= samplesLeft:
		notesLeft <= samplesLeft

		# construction
		piece.append(str(i))
		samplesLeft -= addBy

		# need too many notes check
		notesLeft -= 1
		if notesLeft < 0: return "-1"

		# if need to start saving notes
		if notesLeft > samplesLeft:
			piece.pop(-1)
			samplesLeft += addBy
			notesLeft += 1
			break
		# prepare for next iteration
		i = i % maxPitch + 1
		addBy = min(addBy + 1, maxPitch)
	# add the remainder
	if samplesLeft > 0:
		if notesLeft == 0: return "-1"
		# wizard math. do not question. lots of off by 1 errors, relatively easy to calculate
		targetSamplesLeft = notesLeft - 1
		piece.append(piece[-(samplesLeft - targetSamplesLeft)])
		# fill to end
		piece += [str(piece[-1])] * max(0, (totalNoteCount - len(piece)))
	return " ".join(piece)
totalNoteCount, maxPitch, totalSamples = map(int, input().split())
print(solve(totalNoteCount, maxPitch, totalSamples))

# ====TESTING====
# from random import randint
# totalSamples, totalNoteCount = 0,1
# while totalSamples < totalNoteCount:
# 	totalNoteCount, maxPitch, totalSamples = (randint(1, 20), 4, randint(1, 20))
# print(f"notes: {totalNoteCount}, max: {maxPitch}, samples: {totalSamples}")
# assert(solve(3, 2, 5) == "1 2 1")
# assert(solve(5, 5, 14) == "1 2 3 4 1")
# assert(solve(5, 5, 50) == "-1")
# assert(solve(6, 9, 10) == "1 2 3 2 2 2")
# assert(solve(5, 3, 11) == "1 2 3 1 3")