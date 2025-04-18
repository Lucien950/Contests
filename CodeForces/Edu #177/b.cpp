#include <array>
#include <cassert>
#include <cstdint>
#include <iostream>

using namespace std;

constexpr int MAX_N = 1e5;
static array<int, MAX_N> a;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int64_t n, k, x;
	cin >> n >> k >> x;
	int64_t sum = 0;
	for (int i = 0; i < n; i++) {
	  cin >> a[i];
	  sum += a[i];
	}
	int64_t min_range = 0;
	min_range += n * (x / sum); // add entire cycles
	x %= sum;
	for (int64_t i = n - 1; x > 0; min_range++, i--) {
	  assert(i >= 0);
	  x -= a[i];
	}
	cout << max(0LL, n * k - (min_range - 1)) << endl;
  }
}