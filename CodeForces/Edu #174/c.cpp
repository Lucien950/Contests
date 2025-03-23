#include <array>
#include <cstdint>
#include <iostream>

using namespace std;

static array<uint16_t, static_cast<size_t>(2e5 + 1)> a;
static array<array<uint64_t, static_cast<size_t>(2e5 + 1)>, 3> dp;

constexpr uint64_t MOD = 998244353;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
	  cin >> a[i];
	}

	dp[0][0] = 0;
	dp[1][0] = 0;
	dp[2][0] = 0;
	for (int i = 0; i < n; i++) {
	  if (i - 1 >= 0) {
		dp[0][i] = dp[0][i - 1];
		dp[1][i] = dp[1][i - 1];
		dp[2][i] = dp[2][i - 1];
	  }
	  switch (a[i]) {
	  case 1:
		dp[0][i] = (dp[0][i] + 1) % MOD;
		break;
	  case 2:
		dp[1][i] = (dp[1][i] * 2 + dp[0][i]) % MOD;
		break;
	  case 3:
		dp[2][i] = (dp[2][i] + dp[1][i]) % MOD;
		break;
	  default:
		throw std::exception();
	  }
	}
	cout << dp[2][n - 1] << endl;
  }
}