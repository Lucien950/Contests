#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>

using namespace std;

static uint32_t square_dist_to_button(const uint32_t x, const uint32_t y) {
  return (x - 144) * (x - 144) + (y - 84) * (y - 84);
}

struct stone {
  uint32_t x, y;
  auto operator<=>(const stone& other) const {
	return square_dist_to_button(x, y) <=> square_dist_to_button(other.x, other.y);
  }
};
static array<stone, 8> red_stones;
static array<stone, 8> yellow_stones;

static uint32_t update_score(const array<stone, 8>& winner, const uint32_t winner_n, const stone& best_loser) {
  uint32_t out;
  for (out = 0; out < winner_n && winner[out] < best_loser; out++)
	;
  return out;
}

int main() {
  uint32_t red = 0, yellow = 0;
  for (int i = 0; i < 10; i++) {
	uint32_t red_n;
	cin >> red_n;
	for (uint32_t j = 0; j < red_n; j++)
	  cin >> red_stones[j].x >> red_stones[j].y;

	uint32_t yellow_n;
	cin >> yellow_n;
	for (uint32_t j = 0; j < yellow_n; j++)
	  cin >> yellow_stones[j].x >> yellow_stones[j].y;

	if (red_n == 0) {
	  yellow += yellow_n;
	  continue;
	}
	if (yellow_n == 0) {
	  red += red_n;
	  continue;
	}
	// red_n > 0 && yellow_n > 0

	sort(red_stones.begin(), red_stones.begin() + red_n);
	sort(yellow_stones.begin(), yellow_stones.begin() + yellow_n);

	if (red_stones[0] < yellow_stones[0]) {
	  red += update_score(red_stones, red_n, yellow_stones[0]);
	} else if (yellow_stones[0] < red_stones[0]) {
	  yellow += update_score(yellow_stones, yellow_n, red_stones[0]);
	} else {
	  // equal distance to button
	}
  }
  cout << red << ' ' << yellow << endl;
}