#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n; // 6 <= n <= 100
	cin >> n;

	cout << "1 ";
	for (int i = 1; i <= n - 3; i++) {
	  cout << i << " ";
	}
	cout << "1 2" << endl;
  }
}