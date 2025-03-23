#include <array>
#include <climits>
#include <iostream>
using namespace std;

static array<int, static_cast<size_t>(1e5 + 1)> h;

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
	cin >> h[i];
  }

  array<int, static_cast<size_t>(1e5 + 1)> dp;
  fill(dp.begin(), dp.end(), INT_MAX);
  dp[0] = 0;

  for (int i = 0; i < n; ++i) {
	if (i + 1 < n)
	  dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i + 1] - h[i]));
	if (i + 2 < n)
	  dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i + 2] - h[i]));
  }

  cout << dp[n - 1] << endl;
}