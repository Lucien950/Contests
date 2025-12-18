from bisect import bisect_left, bisect_right
from dataclasses import dataclass
from itertools import combinations
from enum import Enum
from time import time

@dataclass
class VerticalLine:
	y1: int
	y2: int
	x: int

@dataclass
class HorizontalLine:
	x1: int
	x2: int
	y: int

vertical_lines: list[VerticalLine] = []
horizontal_lines: list[HorizontalLine] = []

class Direction(Enum):
	Up = 1
	Down = 2
	Left = 3
	Right = 4

def get_step_dir(a: tuple[int, int], b: tuple[int, int]) -> Direction:
	if a[0] == b[0]: return Direction.Up if b[1] > a[1] else Direction.Down
	elif a[1] == b[1]: return Direction.Right if b[0] > a[0] else Direction.Left
	else: raise ValueError("Points are not aligned")


def line_no_intersect(a: tuple[int, int], b: tuple[int, int]) -> bool:
	"""
	checks that a, b does not intersect any lines
	"""
	match get_step_dir(a,b):
		case Direction.Up | Direction.Down:
			y1, y2 = min(a[1], b[1]), max(a[1], b[1])
			# binary search for horizontal lines in range
			for hline in horizontal_lines[
				bisect_left(horizontal_lines, y1, key=lambda line: line.y):
				bisect_right(horizontal_lines, y2, key=lambda line: line.y)
			]:
				if y1 < hline.y < y2 and hline.x1 < a[0] < hline.x2:
					return False
			return True
		case Direction.Left | Direction.Right:
			x1, x2 = min(a[0], b[0]), max(a[0], b[0])
			for vline in vertical_lines[
				bisect_left(vertical_lines, x1, key=lambda line: line.x):
				bisect_right(vertical_lines, x2, key=lambda line: line.x)
			]:
				if x1 < vline.x < x2 and vline.y1 < a[1] < vline.y2:
					return False
			return True
		case _:
			raise ValueError("Unknown direction")

def is_online(p: tuple[int, int]) -> bool:
	"""
	checks if point is on any line
	"""
	for vline in vertical_lines[
		bisect_left(vertical_lines, p[0], key=lambda line: line.x):
		bisect_right(vertical_lines, p[0], key=lambda line: line.x)
	]:
		if vline.y1 <= p[1] <= vline.y2:
			return True
	for hline in horizontal_lines[
		bisect_left(horizontal_lines, p[1], key=lambda line: line.y):
		bisect_right(horizontal_lines, p[1], key=lambda line: line.y)
	]:
		if hline.x1 <= p[0] <= hline.x2:
			return True
	return False

def is_inside(p: tuple[int, int]) -> bool:
	"""
	raycast to left
	- (could optimize to check which direction has less lines to intersect?)
	and count intersections
	"""
	if is_online(p): return True
	intersection_count: int = 0
	edging_dir = None
	# for all vertical lines with x < p[0] check if they intersect
	for vl in vertical_lines:
		if p[0] <= vl.x:
			# done now
			break
		if not (vl.y1 <= p[1] <= vl.y2):
			continue
		if edging_dir is not None:
			assert p[1] == vl.y1 or p[1] == vl.y2
			intersection_count += edging_dir == (Direction.Down if p[1] == vl.y1 else Direction.Up)
			edging_dir = None
		elif p[1] == vl.y1 or p[1] == vl.y2: # not edging but need to start edging
			edging_dir = Direction.Up if p[1] == vl.y1 else Direction.Down
		elif vl.y1 < p[1] < vl.y2: # normal intersection
			intersection_count += 1
	assert edging_dir is None
	return intersection_count % 2 == 1

def contained(a: tuple[int, int], b: tuple[int, int]) -> bool:
	edging: bool = a[0] == b[0] or a[1] == b[1]
	p1: tuple[int, int] = (a[0], b[1])
	p2: tuple[int, int] = (b[0], a[1])
	inside: bool = edging or (is_inside(p1) and is_inside(p2))
	if not inside:
		return False
	no_line_intersections: bool = line_no_intersect(a, p1) and line_no_intersect(p1, b) and line_no_intersect(a, p2) and line_no_intersect(p2, b)\
		if not edging else line_no_intersect(a, b)
	if not no_line_intersections:
		return False
	return True


points: list[tuple[int, int]] = [
	(line[0], line[1])
	for line in [
		list(map(int, line.strip().split(",")))
		for line in open("9.in").readlines()
	]
]

for (x1, y1), (x2, y2) in zip(points, points[1:] + points[:1]):
	d: Direction = get_step_dir((x1, y1), (x2, y2))
	# this assumes that there are no linearly independent lines
	# this assumes there are no zero-length lines

	if d in (Direction.Up, Direction.Down):
		assert y1 != y2
		vertical_lines.append(VerticalLine(min(y1, y2), max(y1, y2), x1))
	elif d in (Direction.Left, Direction.Right):
		assert x1 != x2
		horizontal_lines.append(HorizontalLine(min(x1, x2), max(x1, x2), y1))
	else:
		raise ValueError("Unknown direction")

vertical_lines.sort(key=lambda line: line.x)
horizontal_lines.sort(key=lambda line: line.y)


out: int = 0
for a, b in combinations(points, 2):
	if not contained(a, b):
		continue
	out = max(out, (abs(a[0]-b[0])+1) * (abs(a[1]-b[1]) + 1))
print(out)