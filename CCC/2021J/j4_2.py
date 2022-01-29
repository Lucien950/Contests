from collections import Counter
shelf = list(input())
l, m, s = shelf.count("L"), shelf.count("M"), shelf.count("S")
displaced = [0 for _ in range(6)]

for i, (start, end) in enumerate(zip([0, l, l+m], [l, l+m, l+m+s])):
    c = Counter(shelf[start:end])
    if i == 0:
        # looking in the L section
        displaced[0] = c["M"]
        displaced[1] = c["S"]
    elif i == 1:
        # looking in the M section
        displaced[2] = c["L"]
        displaced[3] = c["S"]
    elif i == 2:
        # looking in the S section
        displaced[4] = c["L"]
        displaced[5] = c["M"]

swaps = 0
for i, j in [(0, 2), (1, 4), (3, 5)]:
    k = min(displaced[i], displaced[j])
    swaps += k
    displaced[i] -= k
    displaced[j] -= k

if sum(displaced) != 0:
    swaps += sum(displaced)//3 * 2

print(swaps)