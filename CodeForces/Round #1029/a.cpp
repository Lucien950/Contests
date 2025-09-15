#include <array>
#include <cassert>
#include <iostream>

using namespace std;

static array<int, 10> a;

static bool solve() {
  int n, x;
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
	cin >> a[i];
  }

  bool button_used = false;
  for (int i = 0; i < n; i++) {
	if (a[i] == 0)
	  continue;
	assert(a[i] == 1);
	if (!button_used) {
	  i += x - 1;
	  button_used = true;
	} else {
	  return false;
	}
  }
  return true;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
	cout << (solve() ? "YES\n" : "NO\n");
  }
  cout << flush;
}