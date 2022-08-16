n, cards= int(input()), list(map(int, input().split()))
print([i==j for i, j in zip(cards[:n], cards[n:])].count(True))