#include <algorithm>
#include <array>
#include <cassert>
#include <cstdint>
#include <iostream>
using namespace std;

constexpr size_t MAX_N = 2e5;
static array<int32_t, MAX_N> a;

int main() {
  int t;
  cin >> t;
  while (t--) {
	uint32_t n;
	cin >> n;
	assert(n % 2 == 0);

	for (int i = 0; i < n; i++) {
	  cin >> a[i];
	}
	sort(a.begin(), a.begin() + n);

	uint32_t max_gap = 0;
	for (int i = 0; i < n / 2; i++) {
	  max_gap = max(max_gap, static_cast<uint32_t>(abs(a[2 * i] - a[2 * i + 1])));
	}
	cout << max_gap << "\n";
  }
  cout << flush;
}