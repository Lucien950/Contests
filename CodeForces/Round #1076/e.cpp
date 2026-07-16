#include <array>
#include <cmath>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

static constexpr size_t MAX_N = 3e5 + 1;
static array<int, MAX_N> dp;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n;

	fill(dp.begin(), next(dp.begin(), n + 1), -1);
	for (int i = 0; i < n; i++) {
	  int k;
	  cin >> k;
	  dp[k] = 1;
	}

	for (int i = 1; i <= n; i++) {
	  for (int j = 2; j <= i / j; j++) {
		if (i % j != 0)
		  continue;
		if (dp[j] == -1 || dp[i / j] == -1)
		  continue;
		dp[i] = dp[i] == -1 ? dp[j] + dp[i / j] : min(dp[i], dp[j] + dp[i / j]);
	  }
	}

	// output
	for (int i = 1; i <= n; i++)
	  cout << dp[i] << ' ';
	cout << '\n';
  }
  cout << flush;
}