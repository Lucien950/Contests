#include <array>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

static constexpr size_t MAX_ROCK_COUNT = 100;

struct Rock {
  int weight;
  int val;
};
static array<Rock, MAX_ROCK_COUNT> rocks;

int main() {
  int rock_count, capacity;
  cin >> rock_count >> capacity;
  for (int i = 0; i < rock_count; i++) {
	cin >> rocks[i].weight >> rocks[i].val;
  }

  vector<uint64_t> dp_at(capacity + 1, 0), dp_prev(capacity + 1, 0);

  for (int r = 0; r < rock_count; r++) {
	const auto& [rock_weight, rock_val] = rocks[r];
	for (int c = 0; c <= capacity; c++) {
	  dp_at[c] = max(dp_prev[c], c - rock_weight < 0 ? 0 : dp_prev[c - rock_weight] + rock_val);
	}
	swap(dp_at, dp_prev);
  }
  cout << dp_prev[capacity] << endl;
}