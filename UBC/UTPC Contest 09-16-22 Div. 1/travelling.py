from math import log, floor
from random import randint
# cityCount = int(input())
# cities = list(map(int, input().split()))
cityCount = 5
cities = [randint(0, 20) for _ in range(cityCount)]
print([bin(city)[2:] for city in cities])
# calculate direct teleportation
adj = [[min(cities[city] & cities[nextCity], (cities[city] ^ (2**(floor(log(cities[city], 2)) + 1)-1)) & (cities[nextCity] ^ (2**(floor(log(cities[nextCity], 2)) + 1)-1))) if nextCity != city else None for nextCity in range(cityCount)] for city in range(cityCount)]

print("\n".join([str(i) for i in adj]))