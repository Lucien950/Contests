#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	uint64_t n, k;
	cin >> n >> k;
	const uint64_t lb_k = 2 * (n - 1);
	if (const uint64_t ub_k = n * (n - 1) / 2 + n / 2; k % 2 != 0 or k < lb_k or k > ub_k) {
	  cout << -1 << endl;
	  continue;
	}
	cout << 1 << ' ' << 2 << '\n';
	if (k == 2) {
	  continue;
	}
	cout << 1 << ' ' << 3 << '\n';
	// append to 2 and 3 as required to eliminate excesses
	// if excess goes to 0, connect everything else to 1 directly
	uint64_t excess = k - lb_k;
	for (uint64_t i = 4; i <= n; i++) {
	  if (excess == 0) {
		cout << 1 << ' ' << i << '\n';
		continue;
	  }
	  const uint64_t max_excess_kill = (i / 2 * 2) - 2; // for odds, the amount to kill is the same as the previous even
	  const uint64_t exceed_kill = min(excess, max_excess_kill);
	  excess -= exceed_kill;
	  cout << (exceed_kill + (i % 2 == 1)) << ' ' << i << '\n';
	}
  }
  cout << flush;
}