questionNum = int(input())
citizens = int(input())
dmoj = list(map(int, input().split()))
peg = list(map(int, input().split()))

ans = 0
dmoj.sort()
peg.sort()
if questionNum == 1:
    ans = sum([max(dmojer, pegger) for dmojer, pegger in zip(dmoj, peg)])
elif questionNum == 2:
    peopleLeft = citizens
    while peopleLeft > 0:
        if dmoj[-1] >= peg[-1]:
            ans += dmoj.pop()
        else:
            ans += peg.pop()
        peopleLeft -= 1

print(ans)