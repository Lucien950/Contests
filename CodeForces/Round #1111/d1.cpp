#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <ranges>
#include <span>
#include <vector>
using namespace std;

bool works(const uint32_t n, const span<uint32_t> a, const span<uint32_t> a_sorted) {
  const size_t k = 1 << n;
  // check if the frequency of elements in chunks of k are the same
  vector<uint32_t> a_buf;
  a_buf.reserve(k);

  for (size_t i = 0; i < a.size(); i += 2 * k) {
	a_buf.clear();
	const size_t count = min(2 * k, a.size() - i);

	ranges::copy(a.subspan(i, count), back_inserter(a_buf));
	ranges::sort(a_buf);

	if (!ranges::equal(a_buf, a_sorted.subspan(i, count))) {
	  return false;
	}
  }
  return true;
}

int main() {
  int t;
  constexpr size_t MAX_N = 1e6;
  static array<uint32_t, MAX_N> a_buf;
  static array<uint32_t, MAX_N> a_sorted_buf;
  cin >> t;
  while (t--) {
	uint32_t n, q;
	cin >> n >> q;
	const span a(a_buf.data(), n);
	const span a_sorted(a_sorted_buf.data(), n);
	assert(q == 0);

	for (size_t i = 0; i < n; i++) {
	  cin >> a[i];
	}
	for (size_t i = 0; i < q; i++) {
	  // we'll do this in d2.cpp
	}

	ranges::copy(a, a_sorted.begin());
	ranges::sort(a_sorted);

	if (ranges::equal(a, a_sorted)) {
	  cout << 0 << '\n';
	  continue;
	}

	// figure out if a is k-sortable (with k = 1<<n)
	int32_t l = 0, r = 20;
	while (l < r) {
	  // do something with mid
	  if (const uint32_t mid = (l + r) / 2; works(mid, a, a_sorted)) {
		// works :)
		r = mid;
	  } else {
		// doesn't work :(
		l = mid + 1;
	  }
	}
	cout << (1 << l) << '\n';
  }
  cout << flush;
}