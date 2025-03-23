#include <array>
#include <climits>
#include <iostream>
using namespace std;

static array<int, static_cast<size_t>(1e5 + 1)> h;

int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
	cin >> h[i];
  }

  array<int, static_cast<size_t>(1e5 + 1)> dp{};
  fill(dp.begin(), dp.end(), INT_MAX);
  dp[0] = 0;

  for (int i = 0; i < n; ++i) {
	for (int j = 1; j <= k; ++j) {
	  if (i + j < n)
		dp[i + j] = min(dp[i + j], dp[i] + abs(h[i + j] - h[i]));
	}
  }

  cout << dp[n - 1] << endl;
}