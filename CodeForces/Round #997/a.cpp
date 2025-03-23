#include <array>
#include <cstdint>
#include <iostream>
using namespace std;

static array<int, 101> x;
static array<int, 101> y;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
	  cin >> x[i];
	  cin >> y[i];
	}

	// int64_t out = 4 * m * n;
	uint64_t out = 4 * m;
	for (int i = 1; i < n; i++) {
	  out += 2 * x[i] + 2 * y[i];
	}
	cout << out << endl;
  }
}