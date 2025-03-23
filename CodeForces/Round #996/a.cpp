#include <cassert>
#include <iostream>

using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
	int n, a, b;
	cin >> n >> a >> b;
	assert(a != b);
	const int a_to_end = a > b ? a : n - a, b_to_end = a > b ? b : n - b;
	cout << (a_to_end % 2 == b_to_end % 2 ? "YES" : "NO") << endl;
  }
}