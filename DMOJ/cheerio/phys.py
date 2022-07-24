# https://dmoj.ca/problem/cheerio1j2
studentCount, ballLocation = map(int, input().split())

closestStudentName, closestStudentDistance = None, float('inf')
for _ in range(studentCount):
    name, studentLocation = input().split()
    ballDistance = abs(int(studentLocation) - ballLocation)
    if ballDistance < closestStudentDistance:
        closestStudentDistance = ballDistance
        closestStudentName = name
print(closestStudentName)
