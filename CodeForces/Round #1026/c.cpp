#include <cassert>
#include <cstdint>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n;
	vector<int> d(n);
	for (int i = 0; i < n; i++) {
	  cin >> d[i];
	}

	struct bounds {
	  int lb, ub;
	};
	// contains ub and lb of achievable heights, not ub != lb only because d[i] can be -1
	// THIS DOES NOT MEAN you want to achieve those heights, you still need to thread the needle
	vector<bounds> dp(n);
	bool done = false;
	for (int i = 0; i < n; i++) {
	  int lb, ub;
	  cin >> lb >> ub;
	  if (done)
		continue;
	  if (d[i] == -1) {
		// either clipped by lb, or step forward
		// similarly, either clipped by ub, or step up
		dp[i] = {max(lb, i == 0 ? 0 : dp[i - 1].lb), min(ub, (i == 0 ? 0 : dp[i - 1].ub) + 1)};
	  } else {
		// clipping by ub, lb and step by d[i]
		dp[i] = {max(lb, (i == 0 ? 0 : dp[i - 1].lb) + d[i]), min(ub, (i == 0 ? 0 : dp[i - 1].ub) + d[i])};
	  }
	  if (dp[i].lb > dp[i].ub) {
		done = true;
	  }
	}
	if (done) {
	  cout << "-1\n";
	  continue;
	}

	// recover the result
	vector<int> hsp(n); // represents the height setpoint.
	for (int i = n - 1; i >= 0; i--) {
	  if (i == n - 1) {
		hsp[n - 1] = dp[n - 1].ub; // i wonder if we should do this, i think in theory all values between dp[n-1].lb
		                           // and dp[n-1].ub are valid
		continue;
	  }
	  assert(i + 1 < n);
	  hsp[i] =
	      min(dp[i].ub,
	          hsp[i + 1] - (d[i + 1] != -1 ? d[i + 1] : 0)); // case 2 carry from i + 1, case 1 get reduced to dp[i].ub
	}

	// convert heights representation to delta representation
	int h = 0;
	for (int i = 0; i < n; i++) {
	  if (d[i] == -1) {
		// d[i] is not set, so we can choose either 0 or 1
		// assert(setpoint_h[i] >= h);
		if (h < hsp[i]) {
		  assert(h + 1 == hsp[i]);
		  cout << 1 << " ";
		  h++;
		} else {
		  cout << 0 << " ";
		}
	  } else {
		// d[i] is set to either 0 or 1
		cout << d[i] << " ";
		h += d[i];
	  }
	}
	cout << "\n";
  }
  cout << flush;
}