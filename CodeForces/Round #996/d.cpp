#include <array>
#include <iostream>
using namespace std;

static array<int, 2e5 + 1> a;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n, k, l;
	cin >> n >> k >> l;
	for (int i = 0; i < n; i++) {
	  cin >> a[i];
	}

	int time_at = a[0];
	for (const int& ai : a) {
	}

	cout << time_at << endl;
  }
}