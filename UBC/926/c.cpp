#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int win_factor, max_loss_streak, inital_coins;
	cin >> win_factor >> max_loss_streak >> inital_coins;
	const int net_factor = win_factor - 1;

	bool can_tank_x_rounds = 1 + 1 + 2 + 2 + 3 + 3 + ... < inital_coins;
	cout << (can_tank_x_rounds ? "YES" : "NO") << endl;
  }
}