#include <array>
#include <iostream>

using namespace std;

constexpr size_t MAX_N = 2e5;
static array<int, MAX_N> a;

int main() {
  int t;
  cin >> t;
  while (t--) {
	size_t n;
	cin >> n;

	for (size_t i = 0; i < n; ++i) {
	  cin >> a[i];
	}

	int64_t sum = 0;
	for (size_t i = 0; i < n - 1; ++i) {
	  sum += abs(a[i + 1] - a[i]);
	}

	int64_t max_d = max(abs(a[1] - a[0]), abs(a[n - 1] - a[n - 2]));
	for (size_t i = 1; i < n - 1; ++i) {
	  const int64_t new_points = abs(a[i + 1] - a[i - 1]);
	  const int64_t old_points = abs(a[i + 1] - a[i]) + abs(a[i] - a[i - 1]);
	  max_d = max(max_d, old_points - new_points);
	}
	cout << sum - max_d << endl;
  }
}