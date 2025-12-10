#include <cassert>
#include <cstdint>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

static bool in_bounds(const size_t x, const size_t y, const size_t n) { return x < n && y < n; }
static bool is_square_from_topleft(const size_t y, const size_t x, const vector<vector<bool>>& grid) {
  if (!in_bounds(x, y, grid.size()) || !in_bounds(x + 1, y + 1, grid.size())) {
	return false;
  }
  return grid[y][x] && grid[y][x + 1] && grid[y + 1][x] && grid[y + 1][x + 1];
}

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n;

	// BLACK = TRUE, WHITE = FALSE
	vector grid(n, vector(n, false));

	unordered_set<int64_t> xminy, xplusy;

	uint32_t black_count = 0;
	optional<pair<size_t, size_t>> arb_point = nullopt;
	for (int y = 0; y < n; y++) {
	  for (int x = 0; x < n; x++) {
		char c;
		cin >> c;

		if (c == '#') {
		  grid[y][x] = true;
		  black_count += 1;
		  xminy.insert(x - y);
		  xplusy.insert(x + y);
		  if (!arb_point.has_value())
			arb_point = make_pair(x, y);
		}
	  }
	}

	if (black_count == 4) { // square case
	  assert(arb_point.has_value());
	  const size_t arb_y = arb_point.value().second, arb_x = arb_point.value().first;
	  const bool is_square_upleft = is_square_from_topleft(arb_y - 1, arb_x - 1, grid),
	             is_square_downright = is_square_from_topleft(arb_y, arb_x, grid),
	             is_square_upright = is_square_from_topleft(arb_y - 1, arb_x, grid),
	             is_square_downleft = is_square_from_topleft(arb_y, arb_x - 1, grid);
	  if (is_square_upleft || is_square_downright || is_square_upright || is_square_downleft) {
		cout << "YES\n";
		continue;
	  }
	}

	// note special cases black_count = 0, 1, 2 are all automatically YES
	auto at1 = xminy.begin(), at2 = xplusy.begin();
	const bool up_right_diag = xminy.size() <= 2 && (xminy.size() != 2 || abs(*at1 - *next(at1)) <= 1),
	           down_right_diag = xplusy.size() <= 2 && (xplusy.size() != 2 || abs(*at2 - *next(at2)) <= 1);
	if (up_right_diag || down_right_diag) {
	  cout << "YES\n";
	} else {
	  cout << "NO\n";
	}
  }
}