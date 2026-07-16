#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
using namespace std;

static constexpr size_t MAX_N = 2e5;
static array<int32_t, MAX_N> a_buf;
static array<uint32_t, MAX_N> b_buf;

static int64_t solve(const span<int32_t> a, const span<uint32_t> b) {
  int64_t out = 0;
  // out += abs(sum(a[0: b[0]]));
  {
	int64_t sum = 0;
	for (size_t j = 0; j <= b[0]; j++) {
	  sum += a[j];
	}
	out += abs(sum);
  }
  for (size_t i = 0; i < b.size() - 1; i++) {
	// out += abs(sum(a[b[i]: b[i + 1]]));
	int64_t sum = 0;
	for (size_t j = b[i] + 1; j <= b[i + 1]; j++) {
	  sum += a[j];
	}
	out += abs(sum);
  }
  {
	// out += sum(a[b[m-1]: n]);
	for (size_t j = b[b.size() - 1] + 1; j < a.size(); j++) {
	  out += a[j];
	}
  }
  return out;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
	size_t n, m;
	cin >> n >> m;
	for (size_t i = 0; i < n; ++i) {
	  cin >> a_buf[i];
	}
	for (size_t i = 0; i < m; ++i) {
	  cin >> b_buf[i];
	  b_buf[i]--;
	}
	const span a(a_buf.data(), n);
	const span b(b_buf.data(), m);
	ranges::sort(b);
	cout << solve(a, b) << "\n";
  }
  cout << flush;
}