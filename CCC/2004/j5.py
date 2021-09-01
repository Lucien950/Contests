class Point:
	def __init__(self, x, y):
		self.x = x
		self.y = y

	def __lt__(self, other):
		return self.x < other.x or ( self.x == other.x and self.y < other.y )

class Segment:
	def __init__(self, p1, p2, dir):
		self.p1 = min(p1, p2)
		self.p2 = max(p1, p2)
		self.dir = dir

	def d(self):
		if self.p1.y == self.p2.y:
			return 1
		else:
			return -1

	def len(self):
		if self.d() == 1:
			return self.p2.x - self.p1.x
		else:
			return self.p2.y - self.p1.y

lvl, width, x = map(int, input().split())
a = [Segment(Point(0,1),Point(width,1),1)]

for level in range(lvl):
	temp = []
	for i in range(len(a)-1, -1, -1):
		seg = a[i]
		sp1 = seg.p1
		sp2 = seg.p2
		newChunk = int(seg.len() / 3)
		if seg.d() == 1:
			p1 = Point(sp1.x + newChunk, sp1.y)
			p2 = Point(sp1.x + newChunk, sp1.y + seg.d()*newChunk)
			p3 = Point(sp1.x + 2*newChunk, sp1.y + seg.d()*newChunk)
			p4 = Point(sp1.x + 2*newChunk, sp1.y)
		else:
			p1 = Point(sp1.x, sp1.y + newChunk)
			p2 = Point(sp1.x + seg.dir * newChunk, sp1.y + newChunk)
			p3 = Point(sp1.x + seg.dir * newChunk, sp1.y + 2 * newChunk)
			p4 = Point(sp1.x, sp1.y + 2 * newChunk)

		# s1
		temp.append(Segment(sp1, p1, seg.dir))
		# s2
		temp.append(Segment(p1, p2, -1))
		# s3
		temp.append(Segment(p2, p3, seg.dir))
		# s4
		temp.append(Segment(p3, p4, 1))
		# s5
		temp.append(Segment(p4, sp2, seg.dir))
	a = temp

returns = [False] * 81
for seg in a:
	if seg.p1.x == seg.p2.x and seg.p1.x == x:
		for i in range(seg.p1.y, seg.p2.y):
			returns[i] = True
	elif seg.p1.x <= x <= seg.p2.x:
		returns[seg.p1.y] = True

print(" ".join(map(str, [i for i,x in enumerate(returns) if x])))
