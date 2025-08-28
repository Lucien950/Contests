#include <array>
#include <cassert>
#include <iostream>

using namespace std;

static array<int, static_cast<size_t>(5e3)> a;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
	  cin >> a[i];
	}

	int at = 0, inversions = 0;
	for (int i = 0; i < n; i++) {
	  const int compliment = 2 * n - a[i];
	  const int low = min(a[i], compliment), high = max(a[i], compliment);
	}
	cout << "\n";

	cout << inversions << "\n";
  }
  cout << flush;
}