#include <algorithm>
#include <array>
#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n;
	static array<int, 50> a{0};
	for (int i = 0; i < n; ++i) {
	  cin >> a[i];
	}
	sort(a.begin(), a.begin() + n);

	optional<array<int, 50>::iterator> min_even_pos, min_odd_pos, max_even_pos, max_odd_pos;
	for (int i = 0; (!min_even_pos.has_value() || !min_odd_pos.has_value()) && i < n; ++i) {
	  if (a[i] % 2 == 0 && !min_even_pos.has_value()) {
		min_even_pos = a.begin() + i;
	  }
	  if (a[i] % 2 == 1 && !min_odd_pos.has_value()) {
		min_odd_pos = a.begin() + i;
	  }
	}
	for (int i = n - 1; (!max_even_pos.has_value() || !max_odd_pos.has_value()) && i >= 0; --i) {
	  if (a[i] % 2 == 0 && !max_even_pos.has_value()) {
		max_even_pos = a.begin() + i;
	  }
	  if (a[i] % 2 == 1 && !max_odd_pos.has_value()) {
		max_odd_pos = a.begin() + i;
	  }
	}

	long long res = LONG_LONG_MAX;
	if (min_even_pos.has_value() && max_even_pos.has_value()) {
	  res = min(res, n - (max_even_pos.value() - min_even_pos.value() + 1));
	}
	if (min_odd_pos.has_value() && max_odd_pos.has_value()) {
	  res = min(res, n - (max_odd_pos.value() - min_odd_pos.value() + 1));
	}
	cout << res << "\n";
  }
  cout << flush;
}