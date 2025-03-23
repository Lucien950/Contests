#include <array>
#include <iostream>

using namespace std;

static array<bool, 102> b;

bool ok(const int n) {
  for (int i = 0; i < (n - 2) - 2; i++) {
	if (b[i] && !b[i + 1] && b[i + 2])
	  return false;
  }
  return true;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n;
	for (int i = 0; i < n - 2; i++) {
	  cin >> b[i];
	}
	cout << (ok(n) ? "YES" : "NO") << endl;
  }
}