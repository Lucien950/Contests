from sys import prefix


riceBallCount = int(input())
riceBalls = list(map(int, input().split())) + [0]
# prefix sum of riceBalls
prefixSum = [0]
for i in range(1, len(riceBalls)):
    prefixSum.append(prefixSum[i-1] + riceBalls[i])

# dp[i][j] = combine all rice balls between i and j
dp = [[-1 for _ in range(riceBallCount)] for _ in range(riceBallCount)]
for i in range(riceBallCount):
    dp[i][i] = riceBalls[i]-riceBalls[i-1]

res = 0
for distance in range(riceBallCount):
    for l in range(1,riceBallCount - distance):
        r = l + distance
        l2, r2 = l, r
        while(l2 + 1 < r2):
            if dp[l][l2] != -1 and dp[r][r2] != -1 and dp[l][l2] == dp[r][r2]:
                if l2 + 1 == r2 or dp[l2 + 1][r2 -1] != -1:
                    dp[l][r] = max(dp[l][r], prefixSum[r] - prefixSum[l-1])
            if prefixSum[l2] - prefixSum[l-1] < prefixSum[r] - prefixSum[r2-1]:
                l2 += 1
            else:
                r2 -= 1
        res = max(res, dp[l][r])

print(res)