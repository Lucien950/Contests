# tower of hanoi

while(True):
    coins = int(input())
    if coins == 0:
        break
    initalOrder = list(map(int, input.split()))
    