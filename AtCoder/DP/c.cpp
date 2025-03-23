#include <array>
#include <climits>
#include <iostream>

using namespace std;

static array<int, static_cast<size_t>(1e5 + 1u)> a;
static array<int, static_cast<size_t>(1e5 + 1u)> b;
static array<int, static_cast<size_t>(1e5 + 1u)> c;

enum class Activity { NONE, A, B, C };

static array<array<int, 3>, static_cast<size_t>(1e5 + 1)> dp{};

int main() {
  int n;
  cin >> n;

  dp.fill({INT_MAX, INT_MAX, INT_MAX});

  for (int i = 0; i < n; i++) {
	cin >> a[i] >> b[i] >> c[i];
  }

  dp[0] = {0, 0, 0};

  for (int i = 0; i < n; i++) {
	dp[i + 1][0] = max(dp[i][1], dp[i][2]) + a[i];
	dp[i + 1][1] = max(dp[i][0], dp[i][2]) + b[i];
	dp[i + 1][2] = max(dp[i][0], dp[i][1]) + c[i];
  }

  cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << endl;
}