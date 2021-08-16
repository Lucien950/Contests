# https://dmoj.ca/problem/ds1

class Fenwick:
	originalArray = []
	fen = []
	def __init__(self, a, size = 0):
		self.originalArray = a
		self.fen = [0] * (len(a) + 1) if not size else [0] * size
		for i in range(len(a)):
			self.add(i, a[i])
	#FUCKING BULLSHIT
	@staticmethod
	def lsb(q):
		return q & (-q)

	#DOESN'T APPEND, "+= OPERATION"
	def add(self, arrPos, diff):
		# 1 indexing
		arrPos += 1
		while arrPos < len(self.fen):
			self.fen[arrPos] += diff
			arrPos += self.lsb(arrPos)

	#sum from L to R
	def query(self, l:int, r:int):
		l+= 1
		r+= 1
		if l == 1:
			return self.queryInner(r)
		else:
			return self.queryInner(r) - self.queryInner(l-1)
	#sum from 0 to Q
	def queryInner(self, q: int):
		res = 0
		while q > 0:
			res = res + self.fen[q]
			q -= self.lsb(q)
		return res

	def updateFreq(self, arrPos:int, diff:int):
		self.add(arrPos, diff)
		self.originalArray[arrPos] += diff

	def update(self, arrayPos:int, val:int):
		#update the frequency list
		#old -1
		freqFenwick.updateFreq(self.originalArray[arrayPos], -1)
		#new +1
		freqFenwick.updateFreq(val, 1)

		#updaate this fenwick tree
		self.add(arrayPos, val - self.originalArray[arrayPos])
		self.originalArray[arrayPos] = val


n, m = map(int, input().split())
arr = list(map(int, input().split()))
fenwick = Fenwick(arr)
ops = []
for opCount in range(m):
	ops.append(input().split())

freqList = [0] * 100001
for i in arr:
	freqList[i] += 1
freqFenwick = Fenwick(freqList, 100001)

for op in ops:
	opName = op.pop(0)
	if opName == "C":
		fenwick.update(int(op.pop(0)) - 1, int(op.pop(0)))
	elif opName == "S":
		print(fenwick.query(int(op.pop(0))-1, int(op.pop(0))-1))
	elif opName == "Q":
		print(freqFenwick.queryInner(int(op.pop(0)) + 1))
	else:
		print("COCK")