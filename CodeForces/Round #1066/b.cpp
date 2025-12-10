#include <iostream>

using namespace std;

int& max(int& a, int& b) { return a > b ? a : b; }

int main() {
  int t;
  cin >> t;

  while (t--) {
	int n, x, y;
	cin >> n >> x >> y;

	x = abs(x);
	y = abs(y);

	for (int i = 0; i < n; i++) {
	  char c;
	  cin >> c;
	  if (c == '4')
		max(x, y)--;
	  else if (c == '8') {
		x--;
		y--;
	  }
	}

	cout << (x <= 0 && y <= 0 ? "YES" : "NO") << endl;
  }
}