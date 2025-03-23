#include <array>
#include <iostream>
using namespace std;

constexpr size_t MAX_N = 2 * 1e5;
static array<int, MAX_N> a;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
	  cin >> a[i];
	}
	const int play = n - k;
	if (play == 0) {
	  // simulate
	  int first_unmatching_pair_i_times_two;
	  for (first_unmatching_pair_i_times_two = 0; first_unmatching_pair_i_times_two <= n - 2;
	       first_unmatching_pair_i_times_two += 2) {
		if (const int target = first_unmatching_pair_i_times_two / 2 + 1;
		    a[first_unmatching_pair_i_times_two + 1] != target) {
		  break;
		}
	  }
	  cout << first_unmatching_pair_i_times_two / 2 + 1 << endl;
	  continue;
	}

	// play >= 1
	if (a[1] != 1 || a[2] != 1) {
	  cout << 1 << endl;
	  continue;
	}
	// a[1] == 1 and a[2] == 1
	// upper bound of return is 2
	// lets try to get it to 1
	bool found = false;
	for (int i = 1; i <= play + 1; i++) {
	  if (a[i] != 1) {
		found = true;
		break;
	  }
	}
	if (found) {
	  cout << 1 << endl;
	  continue;
	}

	cout << 2 << endl;
  }
}