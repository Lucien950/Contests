#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int a, b;
	cin >> a >> b;
	if (a % 2 == 0) {
	  const int a1 = a / 2, b1 = 2 * b;
	  if ((a1 != b && b1 != a) && (a1 != a && b1 != b)) {
		cout << "YES" << endl;
		continue;
	  }
	}
	if (b % 2 == 0) {
	  const int a1 = 2 * a, b1 = b / 2;
	  if ((a1 != b && b1 != a) && (a1 != a && b1 != b)) {
		cout << "YES" << endl;
		continue;
	  }
	}
	cout << "NO" << endl;
  }
}