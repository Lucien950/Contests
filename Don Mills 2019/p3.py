meshis = list(input())
K = int(input())

count = 0
for i in meshis:
    if i == "S":
        count += 1
    elif i == "R":
        count = 0
    if count >= K:
        print("Spamming")
        break
if count < K:
    print("All good")