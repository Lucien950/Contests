#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int32_t n;
	cin >> n;
	for (int32_t i = 0; i <= n; i++) {
	  const uint64_t base = (1ull << (n-i)) - 1; // namely n-i 1s in a row
	  for (uint64_t j = 0; j < 1ull << max(i-1, 0); j++)
		cout << (base | j << (n - i + 1)) << " ";
	}
	cout << "\n";
  }
  cout << flush;
}