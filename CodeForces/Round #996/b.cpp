#include <array>
#include <iostream>
#include <ranges>
using namespace std;

static std::array<int, static_cast<size_t>(2 * 1e5)> a, b;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
	  cin >> a[i];
	}

	for (int i = 0; i < n; i++) {
	  cin >> b[i];
	}

	bool deficit_used = false, possible = true;
	int deficit = 0, min_surplus = INT_MAX;
	for (int i = 0; i < n; i++) {
	  if (a[i] < b[i]) {
		if (!deficit_used) {
		  deficit += b[i] - a[i];
		  deficit_used = true;
		} else {
		  possible = false;
		  break;
		}
	  } else {
		min_surplus = min(min_surplus, a[i] - b[i]);
	  }
	}

	cout << (possible && deficit <= min_surplus ? "YES" : "NO") << endl;
  }
}