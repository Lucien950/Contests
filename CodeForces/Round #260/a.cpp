#include <iostream>

using namespace std;

unsigned long long cnt[static_cast<size_t>(1e5) + 1];
unsigned long long dp[static_cast<size_t>(1e5) + 1] = {0};

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
	int x;
	cin >> x;
	cnt[x]++;
  }
  dp[1] = cnt[1];
  for (int i = 2; i <= 1e5; i++) {
	dp[i] = max(dp[i - 1], dp[i - 2] + cnt[i] * i);
  }
  cout << dp[static_cast<size_t>(1e5)] << endl;
  return 0;
}