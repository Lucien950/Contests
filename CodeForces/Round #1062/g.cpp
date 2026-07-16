#include <array>
#include <iostream>
#include <numeric>
using namespace std;

int main() {
  static array<uint32_t, 8000> a;
  static array<uint32_t, 8000> c;
  static array<uint64_t, 8001> dp;
  // n^2 = 8e3^2 = 6e7 < 1e9 by 1.5 orders of magnitude (LMAOOOOO)

  int t;
  cin >> t;
  while (t--) {
	uint32_t n;
	cin >> n;
	for (uint32_t i = 0; i < n; i++) {
	  cin >> a[i];
	}
	for (uint32_t i = 0; i < n; i++) {
	  cin >> c[i];
	}
	std::ranges::fill_n(dp.begin(), n + 1, 0);
	// let dp[i] be the max saved cost from keeping a nondecreasing sequence from [0,i)
	for (uint32_t i = 1; i <= n; i++) {
	  for (uint32_t j = 0; j < i; j++) {
		if (j == 0 or a[j - 1] <= a[i - 1]) {
		  const uint64_t candidate_savings = dp[j] + c[i - 1];
		  dp[i] = max(dp[i], candidate_savings);
		}
	  }
	}
	const uint64_t sum_c = std::accumulate(c.begin(), c.begin() + n, 0ull);
	const uint64_t max_savings = *max_element(dp.begin(), dp.begin() + n + 1);
	cout << sum_c - max_savings << '\n';
  }
  cout << flush;
}