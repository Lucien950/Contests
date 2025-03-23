#include <algorithm>
#include <array>
#include <iostream>
using namespace std;

static array<int, 1000> a;
static array<bool, 1001> right_has;
// static array<bool, 1001> is_loose;
// static array<int, 1001> freq;

static bool solve(const int n) {
  std::sort(a.begin(), a.begin() + n);
  std::fill_n(right_has.begin(), n + 1, false);
  for (int i = 0; i < n; i += 2) {
	if (a[i] != a[i + 1])
	  return false;
	right_has[a[i]] = true;
	for (int j = i + 2; a[j] == a[i]; j++)
	  a[j]++;
  }
  return true;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
	  cin >> a[i];
	}
	cout << (solve(n) ? "YES" : "NO") << endl;
  }
}