#include <array>
#include <iostream>
using namespace std;

int main() {
  static array<int, 101> freq;
  int t;
  cin >> t;
  while (t--) {
	size_t n;
	cin >> n;
	freq.fill(0);
	for (size_t i = 0; i < n; i++) {
	  int a;
	  cin >> a;
	  freq[a]++;
	}
	// find the maximum frequency
	const auto max_freq_el = max_element(freq.begin(), freq.end());
	cout << n - *max_freq_el << endl;
  }
}