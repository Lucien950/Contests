#include <array>
#include <cstdint>
#include <iostream>
#include <set>

using namespace std;

static array<int, static_cast<uint64_t>(2e5)> a;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
	  cin >> a[i];
	}

	set<int> x, y;
	int partitions = 0;
	for (int i = 0; i < n; i++) {
	  x.insert(a[i]);
	  y.erase(a[i]);
	  if (y.empty()) {
		// new partition
		y = x;
		partitions += 1;
	  }
	}
	cout << partitions << "\n";
  }
  cout << flush;
}