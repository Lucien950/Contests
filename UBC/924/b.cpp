#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
	  cin >> a[i];

	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());

	int lag_ptr = 0, ans = 0;
	for (int i = 0; static_cast<unsigned long long>(i) < a.size(); i++) {
	  while (a[i] - a[lag_ptr] >= n) {
		lag_ptr++;
	  }
	  const int between_elements = i - lag_ptr + 1;
	  ans = max(ans, between_elements);
	}

	cout << ans << endl;
  }
}