#include <array>
#include <iostream>
using namespace std;

static array<int, 100> a;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	  cin >> a[i];

	if (const size_t zero_count = count(a.begin(), a.begin() + n, 0); zero_count == 0) {
	  cout << "NO";
	} else if (zero_count == 1) {
	  cout << "YES";
	} else {
	  const size_t one_count = count(a.begin(), a.begin() + n, 1);
	  cout << (one_count > 0 ? "YES" : "NO");
	}
	cout << "\n";
  }
}