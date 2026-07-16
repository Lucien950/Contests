#include <concepts>
#include <iostream>
using namespace std;

static constexpr size_t MAX_N = 2e5;

template <integral T> static constexpr T ceildiv(T a, T b) { return (a + b - 1) / b; }

int main() {
  static array<uint32_t, MAX_N> violations_buf{};

  int t;
  cin >> t;
  while (t--) {
	size_t n, q;
	cin >> n >> q;
	// precompute the amount of violations in a range
	// violations[i] gives number of violations from [0:i)
	violations_buf[0] = violations_buf[1] = 0;
	char last, at;
	cin >> last;
	for (size_t i = 1; i < n; i++) {
	  cin >> at;
	  violations_buf[i + 1] = violations_buf[i] + (last == at);
	  last = at;
	}

	for (size_t i = 0; i < q; i++) {
	  size_t l, r, k;
	  cin >> l >> r >> k;
	  const bool ok = ceildiv(violations_buf[r] - violations_buf[l], 2u) <= k;
	  cout << (ok ? "YES" : "NO") << endl;
	}
  }
}