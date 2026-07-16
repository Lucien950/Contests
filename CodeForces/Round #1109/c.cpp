#include <array>
#include <concepts>
#include <cstdint>
#include <iostream>
#include <numeric>
#include <span>
using namespace std;

static constexpr size_t MAX_N = 2e5;
static array<int64_t, MAX_N> a_buf;

template <integral T> T mod(T a, T b) {
  T r = a % b;
  return r < 0 ? r + b : r;
}

int main() {
  int tt;
  cin >> tt;
  while (tt--) {
	uint32_t n, x, y;
	cin >> n >> x >> y;
	span a(a_buf.data(), n);
	for (size_t i = 0; i < n; i++) {
	  cin >> a[i];
	  a[i]--; // just so we can deal with 0-indexed numbers instead of 1-indexed
	}

	bool possible = true;
	for (int64_t i = 0; i < n; i++) {
	  // trying to move element at i to a[i]
	  // i + sx = a[i] mod y or i + sy = a[i] mod x then we are chilling!!! (note that s, t could = 0)
	  // we also need, 0 <= i + sx < n, and 0 <= i + ty < n
	  // namely -i/x <= s < (n - i)/x, and -i/y <= t < (n - i)/y
	  // or on the integers, s\in [-(i//x), (n-i-1)//x], t\in [-(i//y), (n-i-1)//y]
	  // if either interval is sufficiently large (in particular range(s) >= y or range(t) >= x), then instant max win
	  const int64_t min_s = -(i / x), max_s = (n - i - 1) / x;
	  const int64_t min_t = -(i / y), max_t = (n - i - 1) / y;

	  const int64_t g = gcd(static_cast<int64_t>(x), static_cast<int64_t>(y));
	  const int64_t s_cycle_length = static_cast<int64_t>(y) / g, t_cycle_length = static_cast<int64_t>(x) / g;
	  if (g == 1 and (max_s - min_s + 1 >= s_cycle_length or
	                  max_t - min_t + 1 >= t_cycle_length)) { // slight optimization for large n
		continue;
	  }
	  for (int64_t s = min_s; s <= min(max_s, min_s + s_cycle_length - 1); s++) {
		if (const int64_t new_i = i + s * x; mod(new_i - a[i], static_cast<int64_t>(y)) == 0) {
		  goto good;
		}
	  }
	  for (int64_t t = min_t; t <= min(max_t, min_t + t_cycle_length - 1); t++) {
		if (const int64_t new_i = i + t * y; mod(new_i - a[i], static_cast<int64_t>(x)) == 0) {
		  goto good;
		}
	  }
	  possible = false;
	  break;
	good:
	}
	cout << (possible ? "YES" : "NO") << endl;
  }
}
