from bisect import bisect, bisect_left, bisect_right, insort
from dataclasses import dataclass
from enum import Enum

class Direction(Enum):
	Up = 0
	Right = 1
	Down = 2
	Left = 3

@dataclass
class VerticalLine():
	d: Direction
	col: int
	y1: int
	y2: int

@dataclass
class HorizontalLine():
	d: Direction
	row: int
	x1: int
	x2: int

@dataclass
class Position():
	row: int
	col: int
	def __repr__(self) -> str:
		return str((self.row, self.col))

lines: list[str] = open("6.in").readlines()

# lines = """....#.....
# .........#
# ..........
# ..#.......
# .......#..
# ..........
# .#..^.....
# ........#.
# #.........
# ......#...""".strip().splitlines()

rows, cols = len(lines), len(lines[0])
rows_for_col: list[list[int]] = [[] for _ in range(cols)]
cols_for_row: list[list[int]] = [[] for _ in range(rows)]

guard: Position = None # type: ignore
guard_dir: Direction = Direction.Up

for row, line in enumerate(lines):
	for col, c in enumerate(line):
		if c == "#":
			rows_for_col[col].append(row)
			cols_for_row[row].append(col)
		if c == "^":
			assert guard == None, f"guard is not none, namely {guard}"
			guard = Position(row, col)
assert guard is not None

# in order to allow bisect search later
for row in rows_for_col:
	row.sort()
for col in cols_for_row:
	col.sort()

out: int = 0
vertical_paths: list[VerticalLine] = []
horizontal_paths: list[HorizontalLine] = []
while True:
	# find next collision
	cool_rows = rows_for_col[guard.col]
	cool_cols = cols_for_row[guard.row]
	match guard_dir:
		case Direction.Up:
			next_row_index = bisect(cool_rows, guard.row) - 1
			next_row, next_col = cool_rows[next_row_index] + 1 if next_row_index >= 0 else -1, guard.col
		case Direction.Right:
			next_col_index = bisect(cool_cols, guard.col)
			next_row, next_col = guard.row, cool_cols[next_col_index] - 1 if next_col_index < len(cool_cols) else cols
		case Direction.Down:
			next_row_index = bisect(cool_rows, guard.row)
			next_row, next_col = cool_rows[next_row_index] - 1 if next_row_index < len(cool_rows) else rows, guard.col
		case Direction.Left:
			next_col_index = bisect(cool_cols, guard.col) - 1
			next_row, next_col = guard.row, cool_cols[next_col_index] + 1 if next_col_index >= 0 else -1
		case _:
			raise ValueError("guard_dir is not a valid enum value")
	# if no # collision is found, we must leave board, hence leave loop
	leaving = not (1 <= next_row < rows - 1 and 1 <= next_col < cols - 1)

	# count number of steps to the collision
	# if guard.row != next_row:
	# 	steps = abs(guard.row - next_row) + 1
	# elif guard.col != next_col:
	# 	steps = abs(guard.col - next_col) + 1
	# else:
	# 	raise ValueError("impossible")

	# print(f"going from {guard} to {(next_row, next_col)}")

	# count number of intersections with previous paths
	# intersections = 0
	if guard_dir == Direction.Up or guard_dir == Direction.Down:
		# intersect with horizontal lines
		lb_row, ub_row = min(guard.row, next_row), max(guard.row, next_row)
		for path in horizontal_paths[
			max(bisect_left(horizontal_paths, lb_row, key=lambda x: x.row) - 1, 0):
			bisect_right(horizontal_paths, ub_row, key=lambda x: x.row)
		]:
			if not lb_row <= path.row <= ub_row: continue # beside path check
			# if not path.x1 <= guard.col <= path.x2: continue # penetration check
			cycleable: bool = (guard_dir == Direction.Up and path.d == Direction.Right) or \
				(guard_dir == Direction.Down and path.d == Direction.Left)
			if cycleable:
				out += 1
			# intersections += 1
	elif guard_dir == Direction.Left or guard_dir == Direction.Right:
		# intersect with vertical lines
		lb_col, ub_col = min(guard.col, next_col), max(guard.col, next_col)
		for path in vertical_paths[
			max(bisect_left(vertical_paths, lb_col, key=lambda x: x.col) - 1, 0):
			bisect_right(vertical_paths, ub_col, key=lambda x: x.col)
		]:
			if not lb_col <= path.col <= ub_col: continue # beside path check
			# if not path.y1 <= guard.row <= path.y2: continue # penetration check
			cycleable: bool = (guard_dir == Direction.Left and path.d == Direction.Up) or \
				(guard_dir == Direction.Right and path.d == Direction.Down)
			if cycleable:
				out += 1
			# intersections += 1

	# out += steps - intersections
	if leaving: break

	# add the previous line into the lines data
	if guard_dir == Direction.Up or guard_dir == Direction.Down:
		insort(vertical_paths, VerticalLine(
			guard_dir,
			guard.col,
			min(guard.row, next_row),
			max(guard.row, next_row)
		), key=lambda x: x.col)
	elif guard_dir == Direction.Left or guard_dir == Direction.Right:
		insort(horizontal_paths, HorizontalLine(
			guard_dir,
			guard.row,
			min(guard.col, next_col),
			max(guard.col, next_col)
		), key=lambda x: x.row)

	# step the guard
	guard = Position(next_row, next_col)
	guard_dir = Direction((guard_dir.value + 1)%4)

print(out)