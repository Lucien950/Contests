#include <array>
#include <cassert>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <set>

using namespace std;

constexpr size_t MAX_N = 1e6;

static array<uint64_t, MAX_N> at_pos{};
static array<uint64_t, MAX_N + 1> at_pos_prefix{};

static int ceil_div(const int x, const int y) { return 1 + (x - 1) / y; }

static uint64_t range_sum_ex(const size_t start, const size_t end) { return at_pos_prefix[end] - at_pos_prefix[start]; }

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

  uint64_t out = 0;
  // these loops generate combinations of unique points a, b
  for (auto a = locs.begin(); a != locs.end() && *a < ceil_div(total_pos, 2); ++a) {
	for (auto b = next(a); b != locs.end() && *b < *a + ceil_div(total_pos, 2); ++b) {
	  // find the bounds for acceptable third points
	  // a prime and b prime are the points opposite a, b (exclusive)
	  const size_t a_prime = *a + total_pos / 2, b_prime = min(total_pos, *b + ceil_div(total_pos, 2));
	  // this is the range on which to query the amount of third points
	  // sum of points in range (a_prime, b_prime)
	  const uint64_t sum = range_sum_ex(a_prime + 1, b_prime);
	  out += at_pos[*a] * at_pos[*b] * sum;
	}
  }
  cout << out << endl;
}