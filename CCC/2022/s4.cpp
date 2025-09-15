#include <array>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <set>

using namespace std;

constexpr size_t MAX_N = 1e6;

static array<int64_t, MAX_N> at_pos{};
static array<int64_t, MAX_N + 1> at_pos_prefix{};

static int ceil_div(const int x, const int y) { return 1 + (x - 1) / y; }

/**
 * @param start inclusive
 * @param end exclusive
 * @return sum from start to end
 */
static int64_t range_sum(const size_t start, const size_t end) { return at_pos_prefix[end] - at_pos_prefix[start]; }

int main() {
  int total_points, total_pos;
  cin >> total_points >> total_pos;

  set<int> locs;
  for (int i = 0; i < total_points; i++) {
	int loc;
	cin >> loc;
	at_pos[loc]++;
	locs.insert(loc);
  }

  // compute the prefix
  std::partial_sum(at_pos.begin(), at_pos.begin() + total_pos, at_pos_prefix.begin() + 1);

  int64_t window = 0;
  {
	const auto a = locs.begin();
	for (auto b = next(a); b != locs.end() && *b < *a + ceil_div(total_pos, 2); ++b) {
	  // find the bounds for acceptable third points
	  // c_lb and c_ub are the points opposite a, b (exclusive)
	  const size_t c_lb = *a + total_pos / 2 + 1, c_ub = min(*b + ceil_div(total_pos, 2), total_pos);
	  // this is the range on which to query the amount of third points
	  // sum of points in range (c_lb, c_ub)
	  const int64_t sum = range_sum(c_lb, c_ub);
	  window += at_pos[*a] * at_pos[*b] * sum; // number of combinations at a, b, range(c)
	}
  }

  int64_t out = window;
  // these loops generate combinations of unique points a, b
  for (auto a = 1; a < ceil_div(total_pos, 2); ++a) {
	window -= at_pos[a] * range_sum(a + total_pos / 2 - 1, a + ceil_div(total_pos, 2));
	window += at_pos[a + ceil_div(total_pos, 2)] * range_sum(a + total_pos / 2 - 1, a + 2 * ceil_div(total_pos, 2));

	// constrict the Cs which can form triangles with A
	window -= at_pos[a + total_pos / 2] * range_sum(a + 1, a + ceil_div(total_pos, 2));
	cout << window << endl;
	// update window
	out += window;
  }
  cout << out << endl;
}