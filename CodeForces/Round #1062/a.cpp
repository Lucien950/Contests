#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	uint32_t a, b, c, d;
	cin >> a >> b >> c >> d;
	const bool ok = a == b && b == c && c == d;
	cout << (ok ? "YES\n" : "NO\n");
  }
  cout << flush;
}