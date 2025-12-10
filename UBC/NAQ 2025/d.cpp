#include <array>
#include <cstdint>
#include <iostream>

using namespace std;

static array<array<char, 50>, 50> maze;
struct state {
  bool up = false, down = false, right = false, left = false;
};
static array<array<state, 50>, 50> states{};

enum class Directions { UP, DOWN, RIGHT, LEFT };
static Directions turn_right(const Directions cur_dir) {
  switch (cur_dir) {
  case Directions::UP:
	return Directions::RIGHT;
  case Directions::DOWN:
	return Directions::LEFT;
  case Directions::RIGHT:
	return Directions::DOWN;
  case Directions::LEFT:
	return Directions::UP;
  default:
	throw exception{};
  }
}
static Directions turn_left(const Directions cur_dir) {
  switch (cur_dir) {
  case Directions::UP:
	return Directions::LEFT;
  case Directions::DOWN:
	return Directions::RIGHT;
  case Directions::RIGHT:
	return Directions::UP;
  case Directions::LEFT:
	return Directions::DOWN;
  default:
	throw exception{};
  }
}
static pair<int32_t, int32_t> step(const uint32_t x, const uint32_t y, const Directions d) {
  int32_t dx, dy;
  switch (d) {
  case Directions::UP:
	dx = 0;
	dy = -1;
	break;
  case Directions::DOWN:
	dx = 0;
	dy = 1;
	break;
  case Directions::RIGHT:
	dx = 1;
	dy = 0;
	break;
  case Directions::LEFT:
	dx = -1;
	dy = 0;
	break;
  default:
	throw exception{};
  }
  return {x + dx, y + dy};
}
static bool& get_current_state(const uint32_t x, const uint32_t y, const Directions d) {
  auto& [up, down, right, left] = states[y][x];
  switch (d) {
  case Directions::RIGHT:
	return right;
  case Directions::LEFT:
	return left;
  case Directions::UP:
	return up;
  case Directions::DOWN:
	return down;
  default:
	throw exception{};
  }
}
static bool in_bounds(const int32_t x, const int32_t y, const int32_t rows, const int32_t cols) {
  return 0 <= x && x < cols && 0 <= y && y < rows;
}

int main() {
  uint32_t rows, cols;
  cin >> rows >> cols;

  uint32_t start_x, start_y, end_x, end_y;
  cin >> start_y >> start_x >> end_y >> end_x;
  start_y -= 1;
  start_x -= 1;
  end_y -= 1;
  end_x -= 1;

  for (uint32_t row = 0; row < rows; row++) {
	for (uint32_t col = 0; col < cols; col++) {
	  cin >> maze[row][col];
	}
  }

  uint32_t carl_x = start_x, carl_y = start_y;
  auto carl_direction = Directions::RIGHT;
  states[carl_y][carl_x].right = true;
  for (;;) {
	// make a carl step
	if (const auto [new_x, new_y] = step(carl_x, carl_y, turn_left(carl_direction));
	    in_bounds(new_x, new_y, static_cast<int32_t>(rows), static_cast<int32_t>(cols)) && maze[new_y][new_x] == '0') {
	  carl_x = new_x;
	  carl_y = new_y;
	  carl_direction = turn_left(carl_direction);
	} else if (const auto [new_x_1, new_y_1] = step(carl_x, carl_y, carl_direction);
	           in_bounds(new_x_1, new_y_1, static_cast<int32_t>(rows), static_cast<int32_t>(cols)) &&
	           maze[new_y_1][new_x_1] == '0') {
	  carl_x = new_x_1;
	  carl_y = new_y_1;
	} else {
	  carl_direction = turn_right(carl_direction);
	}

	if (carl_x == end_x && carl_y == end_y) {
	  cout << 1 << endl;
	  return EXIT_SUCCESS;
	}
	// mark current state
	bool& cur_state = get_current_state(carl_x, carl_y, carl_direction);
	if (cur_state) {
	  cout << 0 << endl;
	  return EXIT_SUCCESS;
	}
	cur_state = true;
  }
}