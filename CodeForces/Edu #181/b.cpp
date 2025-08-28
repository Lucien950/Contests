#include <cstdint>
#include <iostream>
#include <numeric>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	uint64_t x0, y0, max_move_per_turn;
	cin >> x0 >> y0 >> max_move_per_turn;

	if (x0 <= max_move_per_turn && y0 <= max_move_per_turn) {
	  cout << 1 << "\n";
	  continue;
	}
	const uint64_t g = gcd(x0, y0);
	if (x0 / g <= max_move_per_turn && y0 / g <= max_move_per_turn) {
	  cout << 1 << "\n";
	  continue;
	}

	cout << 2 << "\n";
  }
  cout << flush;
}
