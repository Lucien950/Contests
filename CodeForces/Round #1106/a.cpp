#include <algorithm>
#include <array>
#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n, c;
	cin >> n >> c;

	static array<int, 100> a_buf, b_buf;
	for (int i = 0; i < n; i++) {
	  cin >> a_buf[i];
	}
	for (int i = 0; i < n; i++) {
	  cin >> b_buf[i];
	}

	const std::span<int> a{a_buf.data(), static_cast<size_t>(n)}, b{b_buf.data(), static_cast<size_t>(n)};

	std::optional<int> unsorted_out;
	std::optional<int> sorted_out;

	unsorted_out = 0;
	for (int i = 0; i < n; i++) {
	  if (a[i] < b[i]) {
		unsorted_out = nullopt;
		break;
	  }
	  unsorted_out.value() += abs(a[i] - b[i]);
	}

	ranges::sort(a);
	ranges::sort(b);

	sorted_out = c;
	for (int i = 0; i < n; i++) {
	  if (a[i] < b[i]) {
		sorted_out = nullopt;
		break;
	  }
	  sorted_out.value() += abs(a[i] - b[i]);
	}

	if (not unsorted_out and not sorted_out) {
	  cout << -1 << "\n";
	} else {
	  cout << min(unsorted_out.value_or(INT_MAX), sorted_out.value_or(INT_MAX)) << "\n";
	}
  }
  cout << flush;
}