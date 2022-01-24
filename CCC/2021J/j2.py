people = int(input())
list = [(input(), int(input())) for _ in range(people)]
print(max(list, key=lambda x: x[1])[0])