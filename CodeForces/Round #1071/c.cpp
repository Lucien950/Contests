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
	for (size_t i = 0; i < n; i++) {
	  cin >> a[i];
	}
	sort(a.begin(), next(a.begin(), n));
	cout << max(a[0], a[1] - a[0]) << endl;
  }
}