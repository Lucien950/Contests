#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	size_t n;
	cin >> n;
	if (n % 2 == 0) {
	  cout << "-1" << endl;
	  continue;
	}

	for (size_t i = 0; i < n / 2; i++) {
	  cout << i + 1 << " ";
	  cout << (n - i) << " ";
	}
	if (n % 2 == 1) {
	  cout << (n / 2) + 1;
	}
	cout << endl;
  }
}