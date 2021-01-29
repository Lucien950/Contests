from bisect import bisect_right

competitorsCount, funZone = map(int, input().split())
competitors = sorted(list(map(int, input().split())))

count = 0
for i, competitor in enumerate(competitors):
    count += bisect_right(competitors, competitor + funZone) - i - 1

print(count)