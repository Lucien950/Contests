#include <array>
#include <iostream>
using namespace std;

static constexpr size_t MAX_N = 2e5;
array<uint32_t, MAX_N> a{};

// the key to this problem is that the only way there can be no movement is if all are even or all odd
// suppose WLOG that all are even, and one element is odd
// suppose we want to swap arbitrary positions a, b, with the odd element at c, with a != b != c
// then we can swap a and c, then b and c, then a and c again, which is equivalent to swapping a and b
int main() {
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n;

	bool has_even = false, has_odd = false;
	for (int i = 0; i < n; i++) {
	  cin >> a[i];
	  has_even |= (a[i] % 2 == 0);
	  has_odd |= (a[i] % 2 == 1);
	}
	if (has_even && has_odd) {
	  // sort it normal mode lmao
	  std::sort(a.begin(), a.begin() + n);
	} else {
	  // nothing you can do
	}

	// print a
	for (int i = 0; i < n; i++) {
	  cout << a[i] << " ";
	}
	cout << "\n";
  }
  cout << flush;
}