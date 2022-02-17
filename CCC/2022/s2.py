from collections import defaultdict

studentGroupNumber = defaultdict(int)
x = int(input())
ruleTogether = [input().split() for _ in range(x)]
y = int(input())
ruleApart = [input().split() for _ in range(y)]

g = int(input())
for groupNum in range(g):
    students = input().split()
    for student in students:
        studentGroupNumber[student] = groupNum

violated = 0
# check together groups
for a, b in ruleTogether:
    if studentGroupNumber[a] != studentGroupNumber[b]:
        violated += 1

# check apart groups
for a, b in ruleApart:
    if studentGroupNumber[a] == studentGroupNumber[b]:
        violated += 1

print(violated)