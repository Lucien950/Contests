plantCount = int(input())
waterGrowth = int(input())
plants = list(map(int, input().split()))
print(" ".join(map(lambda x: str(x + 2*waterGrowth), plants)))