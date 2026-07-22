#include <array>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  static vector<bool> a, b;
  constexpr size_t MAX_N = 2e5;
  a.reserve(MAX_N);
  b.reserve(MAX_N);

  int t;
  cin >> t;
  while (t--) {
	size_t n;
	cin >> n;
	a.resize(n);
	b.resize(n);
	for (size_t i = 0; i < n; i++) {
	  int c;
	  cin >> c;
	  a[i] = c == 1;
	}
	for (size_t i = 0; i < n; i++) {
	  int c;
	  cin >> c;
	  b[i] = c == 1;
	}

	uint32_t one_zero_flips = 0;
	bool has_zero_one_flips = false, has_zero_zeros = false, has_one_one = false;
	for (size_t i = 0; i < n; i++) {
	  one_zero_flips += a[i] and not b[i];
	  has_zero_one_flips |= not a[i] and b[i];
	  has_zero_zeros |= not a[i] and not b[i];
	  has_one_one |= a[i] and b[i];
	}

	if (one_zero_flips == 0) {                // no 1->0s
	  if (has_zero_one_flips) {               // namely it's only 0->1 flips
		if (has_zero_zeros and has_one_one) { // has 0 -> 0
		  cout << "2\n";
		  continue;
		}
		// note that 1->1s do nothing as they get converted to 0->1s
		cout << "-1\n";
		continue;
	  }
	  // there are no flips to do
	  cout << "0\n";
	} else if (one_zero_flips % 2 == 1) {
	  // note we can merge the 0->1 flips into this flip
	  cout << "1\n";
	} else {
	  // note we can merge the 0->1 flips into the first flip
	  cout << "2\n";
	}
  }
}