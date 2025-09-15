#include <array>
#include <cstdint>
#include <iostream>

using namespace std;

static array<int, static_cast<size_t>(2e5)> a;

static bool solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
	cin >> a[i];
  }

  const int step = a[1] - a[0];
  for (int i = 1; i < n - 1; i++) {
	if (a[i + 1] - a[i] != step) {
	  return false;
	}
  }

  const int res = min(a[n - 1], a[0]);
  return res >= abs(step) && (res - abs(step)) % (n + 1) == 0;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
	cout << (solve() ? "YES" : "NO") << "\n";
  }
  cout << flush;
}