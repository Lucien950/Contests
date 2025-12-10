#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>

using namespace std;

constexpr size_t MAX_N = 2e5;
static array<bool, MAX_N> present;

int main() {
  int t;
  cin >> t;
  while (t--) {
	present.fill(false);

	uint32_t n, k;
	cin >> n >> k;

	int64_t k_count = 0;
	for (uint32_t i = 0; i < n; ++i) {
	  uint32_t j;
	  cin >> j;
	  present[j] = true;
	  k_count += j == k;
	}

	int64_t need_moved_to = 0;
	for (uint32_t i = 0; i < k; i++) {
	  need_moved_to += !present[i];
	}

	cout << max(need_moved_to, k_count) << "\n";
  }
  cout << flush;
}