#include <array>
#include <iostream>
#include <numeric>

using namespace std;

constexpr size_t MAX_N = 2e5 + 1;
static array<int, MAX_N> a{}, b{};
static array<int, MAX_N> dp{}, prefix{};

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n, q;
	cin >> n >> q;
	for (int i = 0; i < n; i++)
	  cin >> a[i];
	for (int i = 0; i < n; i++)
	  cin >> b[i];

	a[n] = dp[n] = 0;
	for (int i = n - 1; i >= 0; i--) {
	  dp[i] = max({dp[i + 1], a[i], a[i + 1], b[i]});
	}

	// construct prefix sum from dp
	partial_sum(dp.begin(), next(dp.begin(), n), next(prefix.begin()));

	for (int i = 0; i < q; i++) {
	  int l, r;
	  cin >> l >> r;
	  cout << prefix[r] - prefix[l - 1] << " ";
	}
	cout << "\n";
  }
  cout << flush;
}