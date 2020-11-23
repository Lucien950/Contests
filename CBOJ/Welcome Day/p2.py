totalCandies = int(input())

# Here, we are brute adding all values to a set, and counting how many didn't go through
# which is the amount of candies to eat
uniqueCandyTypes = set()
for i in range(totalCandies):
    val = int(input())
    uniqueCandyTypes.add(val)

print(totalCandies - len(uniqueCandyTypes))