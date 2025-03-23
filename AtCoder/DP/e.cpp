#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

static constexpr size_t MAX_ROCK_COUNT = 100;
static constexpr size_t MAX_ROCK_WEIGHT = 1e3;
struct Rock {
  uint32_t weight;
  uint32_t val;
};
static array<Rock, MAX_ROCK_COUNT> rocks;

int main() {
  uint32_t rock_count, capacity;
  cin >> rock_count >> capacity;

  uint32_t max_rock_val = 0;
  for (uint32_t i = 0; i < rock_count; i++) {
	cin >> rocks[i].weight >> rocks[i].val;
	max_rock_val = max(max_rock_val, rocks[i].val);
  }

  const size_t MAX_TOTAL_VAL = max_rock_val * rock_count;

  vector<uint64_t> dp_at(MAX_TOTAL_VAL + 1, UINT64_MAX), dp_prev(MAX_TOTAL_VAL + 1, UINT64_MAX);
  dp_prev[0] = 0;
  // dp[i][j] stores the minimum capacity required to achieve value j using the first i rocks.
  // suppose rock 1 has weight 2 and value 3
  // dp[0] = [0, -, -, 2, -, -, -, -, -, -]
  // rock 2 has weight 1 and value 4
  // dp[1] = [0, -, -, 2, 1, -, -, 3, -, -]

  for (uint32_t r = 0; r < rock_count; r++) {
	const auto& [rock_w, rock_v] = rocks[r];
	for (uint64_t w = 0; w <= MAX_TOTAL_VAL; w++) {
	  dp_at[w] =
	      min(dp_prev[w], w < rock_v || dp_prev[w - rock_v] == UINT64_MAX ? UINT64_MAX : dp_prev[w - rock_v] + rock_w);
	}
	swap(dp_at, dp_prev);
  }

  // Filter values and find max
  auto indices = std::views::iota(0, static_cast<int>(dp_prev.size()));
  auto filtered = indices | views::filter([&](const uint64_t x) { return dp_prev[x] <= capacity; });
  if (ranges::empty(filtered)) {
	throw logic_error("No solution found");
  }
  cout << ranges::max(filtered) << endl;
}