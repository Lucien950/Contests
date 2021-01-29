days = int(input())


sw = list(map(int, input().split()))
se = list(map(int, input().split()))
out = 0


# for team in [se, sw]:
#     for i, val in enumerate(team):
#         if i != 0:
#             team[i] = val + team[i-1]
#
# for i in range(days-1,0,-1):
#     if sw[i] == se[i]:
#         out = i+1
#         break

score1 = 0
score2 = 0
for i in range(days):
    score1 += sw[i]
    score2 += se[i]
    if score1 == score2:
        out = i + 1

print(out)