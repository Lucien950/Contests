#include <iostream>
using namespace std;

int main() {
  static array<int, 500> a{};
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
	  cin >> a[i];
	}
	const auto x = max_element(a.begin(), a.begin() + n);
	swap(a[0], *x);
	for (int i = 0; i < n; i++) {
	  cout << a[i] << " ";
	}
	cout << "\n";
  }
  cout << flush;
}