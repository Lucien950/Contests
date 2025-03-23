#include <iostream>

using namespace std;

static bool solve(const int x, const int y) { // note that y >= x always
  const int diff = y - x;                     // diff >= 0
  if (diff == 1) {                            // trivial
	return true;
  }
  if (diff >= 0)
	return false;
  // with carries?
  if ((-diff + 1) % 9 == 0)
	return true;

  return false;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
	int x, y;
	cin >> x >> y;
	cout << (solve(x, y) ? "YES" : "NO") << endl;
  }
}