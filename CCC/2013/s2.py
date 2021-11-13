maxWeight = int(input())
totalCarCount = int(input())
weightOnBridge = 0

lastTrains = []
for carsCrossed in range(totalCarCount):
    thisCar = int(input())
    weightOnBridge += thisCar
    lastTrains.append(thisCar)
    if carsCrossed >= 4: weightOnBridge -= lastTrains.pop(0)
    if weightOnBridge > maxWeight:
        carsCrossed -= 1
        break
print(carsCrossed + 1)