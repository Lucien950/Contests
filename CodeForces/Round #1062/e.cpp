#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>

using namespace std;
static constexpr size_t MAX_N = 2e5;

// o(n)
static bool works(const int32_t gap, const span<int32_t> a, const int32_t x, const uint32_t finding) {
  uint32_t found = 0;
  // gap from 0 to a[0]
  found += max(0, a[0] - (gap - 1));
  if (found >= finding) {
	return true;
  }
  for (uint32_t i = 0; i < a.size() - 1; i++) {
	found += max(0, a[i + 1] - a[i] - 2 * gap + 1);
	if (found >= finding) {
	  return true;
	}
  }
  // gap from a[n-1] to x
  found += max(0, x - (a[a.size() - 1] + (gap - 1)));
  if (found >= finding) {
	return true;
  }
  return false;
}

int main() {
  static array<int32_t, MAX_N> a_buf;
  int t;
  cin >> t;
  while (t--) {
	int32_t n, x;
	uint32_t k;
	cin >> n >> k >> x;
	for (int32_t i = 0; i < n; i++) {
	  cin >> a_buf[i];
	}
	span a(a_buf.data(), n);
	ranges::sort(a);

	// nlog(n) total
	int32_t l = 0, r = x + 1;
	while (l < r) {
	  if (const int32_t mid = (l + r) / 2; works(mid, a, x, k)) {
		l = mid + 1;
	  } else {
		r = mid;
	  }
	}
	// l == the maximum distance away you can put a teleporter
	assert(l == r);
	assert(works(l - 1, a, x, k));
	assert(not works(l, a, x, k));

	const int32_t ans = l - 1;

	uint32_t placed = 0;
	if (ans == 0) {
	  for (uint32_t i = 0; i < k; i++) {
		cout << i << ' ';
	  }
	  placed = k;
	  goto done;
	}

	// gap from 0 to a[0]
	for (int32_t i = 0; i <= a[0] - ans; i++) {
	  cout << i << ' ';
	  placed++;
	  if (placed >= k)
		goto done;
	}
	for (int32_t i = 0; i < n - 1; i++) {
	  for (int32_t j = a[i] + ans; j <= a[i + 1] - ans; j++) {
		cout << j << ' ';
		placed++;
		if (placed >= k)
		  goto done;
	  }
	}
	// gap from a[n-1] to x
	for (int32_t i = a[n - 1] + ans; i <= x; i++) {
	  cout << i << ' ';
	  placed++;
	  if (placed >= k)
		goto done;
	}
  done:
	assert(placed == k);
	cout << '\n';
  }
  cout << flush;
}