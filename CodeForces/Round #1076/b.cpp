#include <array>
#include <iostream>
using namespace std;

constexpr size_t MAX_N = 2e5;
static array<int, MAX_N> base_a;
static array<int, MAX_N> b;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	  cin >> base_a[i];

	for (int i = 0; i < n; i++)
	  b[i] = i;
	sort(b.begin(), b.begin() + n, [](const int x, const int y) { return base_a[x] > base_a[y]; });

	int start = 0, end = 0;
	for (int i = 0; i < n; i++) {
	  // b[i] gives the iths largest element
	  if (base_a[i] != base_a[b[i]]) {
		start = i;
		end = b[i];
		break;
	  }
	}

	reverse(next(base_a.begin(), start), next(base_a.begin(), end + 1));
	for (int i = 0; i < n; i++)
	  cout << base_a[i] << ' ';
	cout << '\n';
  }
  cout << flush;
}