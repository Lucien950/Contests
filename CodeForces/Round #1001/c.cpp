#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <ranges>

using namespace std;

static void diff(array<int64_t, 50>& a, const int len) {
  for (int i = 0; i < len - 1; i++)
	a[i] = a[i + 1] - a[i];
  a[len - 1] = 0;
}

static int64_t sum_array(const array<int64_t, 50>& a, const int len) {
  int64_t out = 0;
  for (int i = 0; i < len; i++)
	out += a[i];
  return out;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n;
	array<int64_t, 50> a{};
	for (int i = 0; i < n; i++)
	  cin >> a[i];
	if (n == 1) {
	  cout << a[0] << endl;
	  continue;
	}
	int64_t out = sum_array(a, n);
	for (int i = n; i >= 2; i--) {
	  diff(a, i);
	  out = max(out, abs(sum_array(a, i)));
	}
	cout << out << endl;
  }
}