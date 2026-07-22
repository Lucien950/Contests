#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	uint32_t n, k, m;
	cin >> n >> k >> m;
	if (k > n) {
	  // otherwise, there is no contiguous subarray of length k
	  cout << "NO\n";
	  continue;
	}
	// k < n
	if (m < k) { // namely we need m/k>=1 aka m >= k
	  cout << "NO\n";
	  continue;
	}
	// m/k>=1

	cout << "YES\n";
	const uint32_t moverk = m / k;
	for (size_t i = 0; i < k - 1; i++) {
	  cout << moverk << ' ';
	}
	cout << (moverk + m % k) << ' ';
	for (size_t i = 0; i < n - k; i++) {
	  cout << "1 ";
	}
	cout << '\n';
  }
  cout << flush;
}