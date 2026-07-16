#include <iostream>
using namespace std;

constexpr uint64_t MAX_N = 2e5;
static array<uint64_t, MAX_N> p;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n, x, y;
	cin >> n >> x >> y;
	string s;
	cin >> s;
	for (int i = 0; i < n; ++i) {
	  cin >> p[i];
	}
  }
}