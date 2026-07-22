#include <cassert>
#include <iostream>
#include <span>
using namespace std;

bool works(const uint32_t k, const size_t n, const span<const uint32_t> freq) {
  if (k == 0)
	return true;
  if (n < 2 * k - (n % 2 == 1)) {
	return false;
  }
  uint32_t s_i = 0;
  for (uint32_t i = 1; i <= k; i++) {
	s_i += freq[i];
	if (s_i < k - 1 + i) { // amount which can be eaten in this set from bob and alice
	  return false;
	}
  }
  return true;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;

  constexpr size_t MAX_N = 101;
  static array<uint32_t, MAX_N> freq;

  while (t--) {
	size_t n;
	cin >> n;
	freq.fill(0);
	for (size_t i = 0; i < n; i++) {
	  size_t x;
	  cin >> x;
	  freq[x]++;
	}
	uint32_t l = 0, r = n + 1;
	while (l < r) {
	  if (const uint32_t mid = (l + r) / 2; works(mid, n, freq)) {
		l = mid + 1;
	  } else {
		r = mid;
	  }
	}
	cout << l - 1 << endl;
	assert(works(l - 1, n, freq));
	assert(not works(l, n, freq));
  }
  cout << flush;
}