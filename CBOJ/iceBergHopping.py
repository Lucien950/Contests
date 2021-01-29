icebergs, jumpLength = map(int, input().split())
times = list(map(int, input().split()))

low_t = 0
high_t = 10**9+1

def jumpAble(t:int, times):
    prev = 0
    for i, sinkTime in enumerate(times):
        if sinkTime < t: #Has it sunk
            if i == 0 or i == icebergs-1:
                return False
            #don't update the prev value
            continue

        if i - prev > jumpLength: #jump to be made is greater than the total possible jump length
            return False

        #Incriment in essesnce
        prev = i
    return True

while high_t - low_t > 1:
    mid = (low_t + high_t)//2
    if jumpAble(mid, times):
        low_t = mid
    else:
        high_t = mid

print(low_t)