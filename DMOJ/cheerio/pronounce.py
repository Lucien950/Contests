# https://dmoj.ca/problem/cheerio1j1
a = input()
vowels = ['a', 'e', 'i', 'o', 'u']
vowelModifier = 1 if a[0] in vowels else 0
bad = False
for i in range(len(a)):
    if a[i] in vowels and i%2==vowelModifier or a[i] not in vowels and i%2!=vowelModifier:
        bad = True
        break
print("YES" if not bad else "NO")