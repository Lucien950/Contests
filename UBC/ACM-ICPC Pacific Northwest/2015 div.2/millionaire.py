from math import e, log


class Question:
	def __init__(self, data):
		self.safe = data[0] == "safe"
		self.prob = float(data[1])
		self.prize = int(data[2])

games, worth = map(int, input().split())
questions = [Question(input().split()) for _ in range(games)]

# calculate expected happiness
eh = sum([q.prob * log(1 + q.prize/worth) for q in questions])
print(eh)