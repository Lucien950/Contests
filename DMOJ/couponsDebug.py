# PAGE 33
# https://dmoj.ca/problem/ecoo13r1p4
from collections import Counter
import copy
from decimal import Decimal

for case in range(5):
	# itemPrices[i] = price of item #i
	itemPrices: list[Decimal] = []
	coupons: list[str] = []

	itemCount = int(input())
	for _ in range(itemCount):
		itemPrices.append(Decimal(input()))
	couponCount = int(input())
	for _ in range(couponCount):
		coupons.append(input())

	itemPrices.sort()
	itemPrices.reverse()
	coupons: Counter[str] = Counter(coupons)
	coupons["BOGO"] = min(coupons["BOGO"], 1)
	explore:list[(int, Decimal, Counter[str], str)] = [(0, Decimal(0), copy.deepcopy(coupons), "")]
	bestPrice = Decimal('Infinity')
	action = ""
	while explore:
		i, price, nowCoupon, lastAction = explore.pop(0)
		if i == len(itemPrices):
			if price < bestPrice:
				bestPrice = price
				action = lastAction
			continue

		percentQueue = [(Decimal('0.8'), "20%")] * nowCoupon["20%"] + [(1, "TAX")] * nowCoupon["TAX"] + [(Decimal('0.9'), "10%")] * nowCoupon["10%"]
		cashQueue = [(50, "$50")] * nowCoupon["$50"] + [(10, "$10")] * nowCoupon["$10"] + [(5, "$5")] * nowCoupon["$5"]
		bogoCount = nowCoupon["BOGO"]
		cashQueue.sort(key=lambda x: x[0])
		cashQueue.reverse()
		# MY FAT DICK
		canMultiply = len(percentQueue) > 0
		canCash = len(cashQueue) > 0
		canBogo = i != len(itemPrices) - 1 and bogoCount > 0

		if canMultiply:
			val, percent = percentQueue.pop(0)
			cock = itemPrices[i] * val
			if percent != "TAX": cock *= Decimal("1.13")
			cock = round(cock, 2)

			nowCoupon[percent] -= 1
			explore.append((i+1, price + cock, copy.deepcopy(nowCoupon), lastAction + f" {percent}"))
			nowCoupon[percent] += 1
		if canCash:
			val, cash = cashQueue.pop(0)
			cock = max(Decimal(0), itemPrices[i] - val)
			cock *= Decimal("1.13")
			cock = round(cock, 2)

			nowCoupon[cash] -= 1
			explore.append((i + 1, price + cock, copy.deepcopy(nowCoupon), lastAction + f" {cash}"))
			nowCoupon[cash] += 1
		if canBogo:
			cock = itemPrices[i]
			cock *= Decimal("1.13")
			cock = round(cock, 2)

			nowCoupon["BOGO"] -= 1
			explore.append((i+2, price + cock, copy.deepcopy(nowCoupon), lastAction + " BOGO"))
			nowCoupon["BOGO"] += 1

		explore.append((i + 1, round(price + itemPrices[i] * Decimal(1.13), 2), copy.deepcopy(nowCoupon), lastAction + " nothin"))

	print(f"The best price is ${bestPrice}")
	print(action)