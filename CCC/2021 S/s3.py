friendCount = int(input())

friends = []
for i in range(friendCount):
    p, w, d = map(int, input().split())
    friends.append((p, w, d))
friends.sort(key=lambda k: k[0])

minFriend, maxFriend = friends[0][0], friends[friendCount-1][0]
field = [0] * (maxFriend + 1)

for friend in friends:
    #up traverse
    curPos = friend[0]
    curPos += friend[2] + 1
    i = friend[1]
    while curPos <= maxFriend:
        field[curPos] += i
        curPos += 1
        i += friend[1]
    #down traverse
    curPos = friend[0]
    curPos -= friend[2] + 1
    i = friend[1]
    while curPos >= 0:
        field[curPos] += i
        curPos -= 1
        i += friend[1]

print(min(field))

#APPROACH 1
# minFriend, maxFriend = min(friends, key=lambda k: k.position), max(friends, key=lambda k: k.position)
# minFriend, maxFriend = minFriend.position, maxFriend.position
# if friendCount == 1: maxFriend += 1
#
# bestWeight = float('inf')
# for position in range(minFriend, maxFriend):
#     sum = 0
#     for friend in friends:
#         #Already in earshot
#         if abs(position - friend.position) <= friend.hearingDistance:
#             continue
#
#         considerPosition = friend.position
#         if position < considerPosition:
#             considerPosition -= friend.hearingDistance
#         elif position > considerPosition:
#             considerPosition += friend.hearingDistance
#         else:
#             continue
#         sum += abs(position - considerPosition) * friend.travel
#     bestWeight = min(sum, bestWeight)
#
# print(bestWeight)