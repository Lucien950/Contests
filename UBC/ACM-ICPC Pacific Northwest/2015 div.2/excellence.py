studentCount = int(input())
studentRatings = sorted([int(input()) for _ in range(studentCount)])
lows, highs = studentRatings[:studentCount//2], studentRatings[studentCount//2:][::-1]
print(min([sum(group) for group in zip(lows, highs)]))