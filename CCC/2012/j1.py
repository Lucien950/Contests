limit = int(input())
speed = int(input())
over = speed - limit
if over <= 0:
    print("Congratulations, you are within the speed limit!")
else:
    if 1 <= over <= 20:
        fine = 100
    elif 21 <= over <= 30:
        fine = 270
    else:
        fine = 500
    print(f"You are speeding and your fine is ${fine}.")