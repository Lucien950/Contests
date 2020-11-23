from itertools import combinations

def checkRightAngled(p1, p2, p3):
	X1, Y1 = p1
	X2, Y2 = p2
	X3, Y3 = p3
	
	A = (int(pow((X2 - X1), 2)) +
		 int(pow((Y2 - Y1), 2)))
	B = (int(pow((X3 - X2), 2)) +
		 int(pow((Y3 - Y2), 2)))
	C = (int(pow((X3 - X1), 2)) +
		 int(pow((Y3 - Y1), 2)))
	
	return ((A > 0 and B > 0 and C > 0) and
			(A == (B + C) or B == (A + C) or
			 C == (A + B)))


pointNum = int(input())
points = []
for i in range(pointNum):
	points.append(tuple(map(int, input().split(" "))))

counter = 0
for p1, p2, p3 in combinations(points, 3):
	counter += 1 if checkRightAngled(p1, p2, p3) else 0

print(counter)
