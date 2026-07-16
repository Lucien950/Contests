#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n, s, x;
	cin >> n >> s >> x;
	for (int i = 0; i < n; i++) {
	  int k;
	  cin >> k;
	  s -= k;
	}
	cout << (s >= 0 and s % x == 0 ? "YES\n" : "NO\n");
  }
  cout << flush;
}