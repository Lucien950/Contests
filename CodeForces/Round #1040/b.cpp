#include <iostream>
#include <numeric>

using namespace std;

static array<int, 3> freq;

int main() {
  int t;
  cin >> t;
  while (t--) {
	freq.fill(0);
	int n, target_sum; // namely remaining_target_sum
	cin >> n >> target_sum;
	for (int i = 0; i < n; i++) {
	  int q;
	  cin >> q;
	  freq[q]++;
	}

	const int a_sum = freq[1] + 2 * freq[2];
	target_sum -= a_sum;

	if (target_sum < 0) {
	  for (int i = 0; i <= 2; i++) {
		for (int j = 0; j < freq[i]; j++) {
		  cout << i << " ";
		}
	  }
	  cout << "\n";
	  continue;
	}
	if (target_sum == 0) {
	  cout << -1 << "\n";
	  continue;
	}

	// check if i can't block 1 cycles
	if (freq[2] == 0 and freq[0] > 0 and freq[1] > 0) {
	  cout << -1 << "\n";
	}

	// i can block 1 cycles
	if (target_sum == 1 and ((freq[0] > 0 and freq[1] > 0) == (freq[2] > 0))) {
	  for (const int i : {0, 2, 1}) {
		for (int j = 0; j < freq[i]; j++) {
		  cout << i << " ";
		}
	  }
	  cout << "\n";
	  continue;
	}

	cout << -1 << "\n";
  }
  cout << flush;
}