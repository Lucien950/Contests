from dataclasses import dataclass

lines = open("12.in").readlines()

@dataclass
class Present:
	body: tuple[str, str, str]
	occ: int = 0

	def __init__(self, body: tuple[str, str, str]) -> None:
		self.body = body
		self.occ = sum(line.count("#") for line in body)

lines_at = 0
presents: list[Present] = []
for i in range(6):
	name = lines[lines_at].strip()[:-1]
	lines_at += 1
	presents.append(Present((
		lines[lines_at].strip(),
		lines[lines_at+1].strip(),
		lines[lines_at+2].strip()
	)))
	lines_at += 4

fitable = 0
# unfitable = 0
nontrivial = 0
for line in lines[lines_at:]:
	line = line.strip()
	dim, *counts_str = line.split()
	dimx,dimy = map(int, dim[:-1].split("x"))

	total_cnt = 0
	total_occ = 0
	for i, cnt in enumerate(map(int, counts_str)):
		total_cnt += cnt
		total_occ += cnt * presents[i].occ

	if 9*total_cnt <= dimx * dimy:
		fitable += 1
	elif total_occ > dimx * dimy:
		# unfitable += 1
		pass
	else:
		# nontrivial += 1
		print(line)
		print(dimx * dimy, dimx * dimy - total_occ)

print(fitable)