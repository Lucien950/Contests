levels = open("3.in").readlines()

# out = 0
# for line in levels:
# 	line = line.strip()
# 	k: list[tuple[int, int]] = [(int(c), i) for i, c in enumerate(line)]
# 	max_value, max_pos = max(k[:-1], key=lambda x: x[0])
# 	max_2_value, _max_2_pos = max(k[max_pos + 1:], key=lambda x: x[0])
# 	joltage = max_value * 10 + max_2_value
# 	out += joltage
# print(out)

out = 0
line_len = len(levels[0].strip())
dp: list[list[int]] = [[0 for _ in range(line_len)] for _ in range(12)]
for line in levels:
	line = line.strip()
	k: list[int] = [int(c) for c in line]
	assert len(k) == line_len
	for x in range(1, 12):
		for i in range(x, len(k)):
			up_sum_max = max([k[j] * 10 + k[i] for j in range(i)]) \
				if x == 1 else max([dp[x-1][j] * 10 + k[i] for j in range(i)])
			dp[x][i] = max(dp[x][i-1], up_sum_max)
	out += max(dp[11])

print(out)