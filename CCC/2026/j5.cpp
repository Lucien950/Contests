#include <cstdint>
#include <iostream>
using namespace std;

uint64_t solve(const int64_t a, const int64_t b, const uint64_t k, const uint64_t t) {
  const uint64_t dist = (a >= b) ? (static_cast<uint64_t>(a) - static_cast<uint64_t>(b))
                                 : (static_cast<uint64_t>(b) - static_cast<uint64_t>(a));
  if (dist % k == 0) {
	if (t == 1) {
	  return dist / k;
	}
	// t == 2
	if (dist == 0)
	  return 2;
	if (k == 1) {
	  return dist;
	}
	if (k == 2) {
	  return dist / k + 1;
	}
	return dist / k + 2;
  }

  // dist % k != 0
  const uint64_t front = dist % k, back = 1 + k - dist % k;
  if (t == 1) {
	return dist / k + min(front, back);
  }
  if (front == back) {
	return dist / k + min(static_cast<uint64_t>(k - 1), 2ull) + min(front, back);
  }
  // t == 2
  return dist / k + min(min(front, back) + 2, max(front, back));
}

int main() {
  int64_t a, b, k, t;
  cin >> a >> b >> k >> t;
  const uint64_t ans = solve(a, b, k, t);
  //  if (ans == 16 and a != 25) {
  // cout << a << ' ' << b << ' ' << k << ' ' << t << endl;
  //  }
  cout << ans << endl;
}
