#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <vector>
using namespace std;

constexpr size_t MAX_WEIGHTS = 2e5;

struct rock_obj {
  uint32_t weight;
  uint32_t index;
  auto operator<=>(const rock_obj& other) const { return weight <=> other.weight; }
};
static array<rock_obj, MAX_WEIGHTS> weights;

int main() {
  int t;
  cin >> t;

  while (t--) {
	uint32_t rock_count;
	uint64_t max_target_weight;
	cin >> rock_count >> max_target_weight;
	for (uint32_t i = 0; i < rock_count; i++) {
	  cin >> weights[i].weight;
	  weights[i].index = i;
	}
	const uint64_t target_weight = (max_target_weight + 1) / 2;
	sort(weights.data(), weights.data() + rock_count, greater());

	uint64_t acc = 0;
	vector<uint32_t> take;
	for (uint32_t i = 0; i < rock_count; i++) {
	  const auto [weight, index] = weights[i];
	  if (acc + weight >= target_weight && acc + weight <= max_target_weight) {
		// WIN!
		cout << take.size() + 1 << endl;
		for (const uint32_t w : take) {
		  cout << w + 1 << ' ';
		}
		cout << index + 1 << endl;
		goto done;
	  }
	  if (acc + weight <= max_target_weight) {
		acc += weight;
		take.push_back(index);
	  }
	}
	cout << -1 << endl;
  done:
  }
}