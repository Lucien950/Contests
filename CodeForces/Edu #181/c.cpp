#include <cstdint>
#include <iostream>

using namespace std;

static uint64_t l, r;

/**
 * @return the number of multiples of a in the range [l, r].
 */
static uint64_t f(const int a) { return r / a - (l - 1) / a; }

int main() {
  int t;
  cin >> t;
  while (t--) {
	cin >> l >> r;
	const uint64_t in_factor = f(2) + f(3) + f(5) + f(7) - f(2 * 3) - f(2 * 5) - f(2 * 7) - f(3 * 5) - f(3 * 7) -
	                           f(5 * 7) + f(2 * 3 * 5) + f(2 * 3 * 7) + f(2 * 5 * 7) + f(3 * 5 * 7) - f(2 * 3 * 5 * 7);
	cout << r - l + 1 - in_factor << "\n";
  }
  cout << flush;
}
