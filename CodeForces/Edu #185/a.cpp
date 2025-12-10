#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n;
	if (n == 1) {
	  cout << 1 << endl;
	  continue;
	}
	if (n == 2) {
	  cout << 9 << endl;
	  continue;
	}
	cout << max(4 * n * n - n - 4, 5 * n * n - 5 * n - 5) << endl;
  }
}