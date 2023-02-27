cases = int(input())
for case in range(cases):
	sellerCount, buyerCount = map(int, input().split())
	connects = []
	sellersBusy = [False for _ in range(sellerCount + 1)]
	buyersBusy = [False for _ in range(buyerCount + 1)]
	while True:
		connection = tuple(map(int, input().split()))
		if connection == (0, 0, 0): break
		connects.append(connection)
	connects.sort(key=lambda x: (x[2], x[0], x[1]), reverse=True)

	total = 0
	for seller, buyer, price in connects:
		if not sellersBusy[seller] and not buyersBusy[buyer]:
			total += price
			sellersBusy[seller] = True
			buyersBusy[buyer] = True
	print(total)