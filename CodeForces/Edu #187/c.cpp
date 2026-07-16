#include <bitset>
#include <cassert>
#include <cstdint>
#include <iostream>
using namespace std;

bool solvable_with(const bitset<64> s_bits, const bitset<64> m_bits, const uint64_t n) {
  array<uint64_t, 64> freq{};
  freq.fill(n);
  int at = 63;
  for (int i = 63; i >= 0; --i) { // bits from the right
	if (not s_bits.test(i))
	  continue;
	// we need to kill a bit at the ith position
	uint64_t left = 1ull << static_cast<uint64_t>(i);
	while (left > 0 and at >= 0) {
	  const uint64_t at_val = 1ull << at;
	  if (at_val > left or freq[at] == 0 or not m_bits.test(at)) {
		at -= 1;
		continue;
	  }
	  const uint64_t have = min(freq[at], left / at_val);
	  freq[at] -= have;
	  left -= have * at_val;
	}
	if (left > 0 or at < 0)
	  return false;
  }
  return true;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
	uint64_t s, m;
	cin >> s >> m;

	// actually i don't think this is necessary?
	if ((s & -s) < (m & -m)) { // unkillable bit
	  cout << -1 << endl;
	  continue;
	}

	uint64_t l = 1, r = s;
	const bitset<64> s_bits(s), m_bits(m);
	while (l < r) {
	  if (const uint64_t mid = l + (r - l) / 2; solvable_with(s_bits, m_bits, mid)) {
		r = mid;
	  } else {
		l = mid + 1;
	  }
	}

	cout << l << '\n';
  }
  cout << flush;
}