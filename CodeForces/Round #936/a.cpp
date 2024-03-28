#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
	  cin >> a[i];

	sort(a, a + n);
	const int medianPosition = static_cast<int>(::ceil(n / 2.0)) - 1;
	int out = 1;
	for (int i = medianPosition + 1; a[medianPosition] == a[i]; i++)
	  out++;
	cout << out << endl;
  }
}