#include <cmath>
#include <cstdint>
#include <iostream>

using namespace std;

static bool is_perfect_square(const uint64_t n) {
  const auto root = static_cast<uint64_t>(sqrt(n));
  return root * root == n;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
	uint64_t n;
	cin >> n;
	if (n <= 1) {
	  cout << -1 << endl;
	  continue;
	}

	if (n * (n + 1) % 2 == 0 && is_perfect_square(n * (n + 1) / 2)) {
	  cout << -1 << endl;
	  continue;
	}

	uint64_t sum = 0;
	for (int i = 1; i <= n; i++) {
	  if (is_perfect_square(sum + i)) {
		cout << i + 1 << " " << i << " ";
		sum += i + i + 1;
		i++;
	  } else {
		cout << i << " ";
		sum += i;
	  }
	}
  }
}