age, birthdate = map(int, input().split())

# adjust the start and end points to the nearest value for which v%225 = birthdate
e = pow(10, age) - (pow(10, age, 225) - birthdate) % 225
s = pow(10, age-1) + (225 - (pow(10, age-1, 225) - birthdate)%225)

assert(0 <= pow(10, age) - e < 225)
assert(0 <= s - pow(10, age-1) < 225)
assert(e % 225 == birthdate)
assert(s % 225 == birthdate)
print((e - s)//225%(10**9+7))