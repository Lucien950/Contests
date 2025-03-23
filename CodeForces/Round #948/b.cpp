#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	unsigned long long x;
	cin >> x;
	const unsigned long long xx = x;
	short a[32] = {0}; // only contains 1, 0, -1, consider with a[0] being the rightmost bit of the output
	// convert x to binary in a
	int n_1;
	for (n_1 = 0; x != 0; n_1++) {
	  a[n_1] = x & 1;
	  x >>= 1;
	}
	assert(x == 0);
	// sweep across a and find ranges of 1s
	int n = n_1;
	for (int r = 0; r < n_1; r++) {
	  if (a[r] == 0)
		continue;
	  // a[r] == 1
	  int l; // l is the first of a that is 0
	  for (l = r + 1; a[l] == 1; l++) {
		a[l] = 0;
	  }
	  if (l > r + 1) {
		a[l] = 1;
		a[r] = -1;
		n = max(n, l + 1);
	  }
	  r = l - 1; // r++ then increments it
	}
	// output
	cout << n << endl;
	for (int i = 0; i < n; i++) {
	  cout << a[i] << " ";
	}
	cout << endl;
  }
  return 0;
}