# https://dmoj.ca/problem/ds1
from collections import Counter

class Fenwick:
	originalArray = []
	fen = []
	def __init__(self, arr):
		self.originalArray = arr
		self.fen = [0] * (len(arr) + 1)
		for i in range(1, len(arr) + 1):
			self.add(i, arr[i-1])

	def updateFreq(self, i:int, val:int):
		try:
			while i >= len(self.originalArray):
				self.originalArray.append(0)
			self.originalArray[i] += val
		except:
			print("COCKING PENIS")
		self.fen = [0] * (len(self.originalArray) + 1)
		for i in range(1, len(self.originalArray) + 1):
			self.add(i, self.originalArray[i - 1])

	def lsb(self, q):
		return q & (-q)
	def add(self, i, diff):
		while i < len(self.fen):
			self.fen[i] += diff
			i += self.lsb(i)
	def update(self, i:int, val:int):
		#update the frequency list
		freqFenwick.updateFreq(self.originalArray[i], -1)
		freqFenwick.updateFreq(val, 1)

		#updaate this fenwick tree
		self.add(i+1, val - self.originalArray[i])
		self.originalArray[i] = val
	def queryInner(self, q: int):
		res = 0
		while q > 0:
			res = res + self.fen[q]
			q -= self.lsb(q)
		return res

	def query(self, l:int, r:int):
		l+= 1
		r+= 1
		if l == 1:
			return self.queryInner(r)
		else:
			return self.queryInner(r) - self.queryInner(l-1)


n, m = map(int, input().split())
arr = list(map(int, input().split()))
fenwick = Fenwick(arr)
ops = []
for opCount in range(m):
	ops.append(input().split())

freqList = [0] * (max(arr) + 1)
for i in arr:
	freqList[i] += 1
freqFenwick = Fenwick(freqList)

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