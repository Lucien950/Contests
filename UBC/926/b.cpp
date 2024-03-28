#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n, k;
	cin >> n >> k;
	const int twoBlocks = ceil(min(k, 4 * n - 4) / 2.0), oneBlocks = max(k - (4 * n - 4), 0);
	cout << twoBlocks + oneBlocks << endl;
  }
}