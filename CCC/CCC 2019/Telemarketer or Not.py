numbers = []
for index in range(4):
    numbers.append(int(input()))
if (numbers[0] == 8 or numbers[0] == 9) and (numbers[3] == 8 or numbers[3] == 9) and numbers[1] == numbers[2]:
    print("ignore")
else:
    print("answer")
