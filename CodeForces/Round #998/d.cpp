#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n;

	int prev;
	cin >> prev;
	bool solvable = true;
	for (int i = 1; i < n; i++) {
	  int a;
	  cin >> a;
	  if (solvable && a < prev) {
		solvable = false;
	  }
	  prev = a - prev;
	}

	cout << (solvable ? "YES" : "NO") << endl;
  }
}