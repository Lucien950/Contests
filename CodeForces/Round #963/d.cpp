#include <cmath>
#include <cstdint>
#include <cstring>
#include <iostream>

using namespace std;

static constexpr size_t MAX = 5e5;

int a[MAX];

bool possible(int test_median, int arrlen, int jump_size, int required_removals) {
  static int dp[MAX]; // you can arrive here with dp[i] numbers larger than the test_median
  memset(dp, 0, arrlen + 1);
  for (int i = 0; i < arrlen; i++) {
	// keep the current value
	if (a[i] > test_median) {
	  dp[i + 1] = max(dp[i + 1], dp[i] + 1);
	}

	// you can also jump with the current value
	if (i + jump_size < arrlen) { // range check
	  dp[i + jump_size] = max(dp[i + jump_size], dp[i]);
	}
  }
  return false;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
	int arrlen, cut_size;
	cin >> arrlen >> cut_size;
	int l = INT_MAX, r = 0;
	for (int i = 0; i < arrlen; i++) {
	  cin >> a[i];
	  l = min(l, a[i]);
	  r = max(r, a[i]);
	}
	int removals_rounds = static_cast<int>(floor((float)arrlen / (float)cut_size));

	while (l < r) {
	  int mid = (l + r) / 2;
	  if (possible(mid, arrlen, cut_size, removals_rounds)) {
		l = mid;
	  } else {
		r = mid - 1;
	  }
	}
	cout << l << endl;
  }
}