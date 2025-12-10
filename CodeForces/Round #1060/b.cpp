#include <array>
#include <cstdint>
#include <iostream>

using namespace std;

static constexpr size_t MAX_N = 2e5;
static array<uint32_t, MAX_N> a;

int main() {
  int t;
  cin >> t;
  while (t--) {
	uint32_t n;
	cin >> n;

	for (size_t i = 0; i < n; i++) {
	  cin >> a[i];
	}

	uint32_t ops = 0;
	if (a[0] >= a[1]) {
	  // a[1] = a[0], a[0] -= 1
	  // namely, one op, and move prefix_max to 1
	  ops += 1;
	}

	uint32_t prefix_max = max(a[0], a[1]);
	for (size_t i = 2; i < n; i++) {
	  if (i % 2 == 0) {
		if (prefix_max > a[i]) // we want to go down on even i
		  continue;
		// a[i-1] <= a[i]
		ops += a[i] - prefix_max + 1;
	  }
	  // else we want to go up on odd i
	  // let a[i] = max(prefix_max, a[i])
	  // we know that prefix_max >= a[i-2] > a[i-1], hence a[i] > a[i-1]

	  prefix_max = max(prefix_max, a[i]);
	}

	cout << ops << "\n";
  }
  cout << flush;
}