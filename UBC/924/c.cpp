#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int pos, num;
	cin >> pos >> num;

	if (num > pos) {
	  cout << 0 << endl;
	  continue;
	}
	if (num == pos) {
	  cout << 1 << endl;
	  continue;
	}

	int ans = 0;
	for (int k = 2; 2 * k <= pos + num; k += 2) {
	  if ((pos - num) % k == 0) {
		ans++;
		cout << k << "up" << endl;
	  }
	  if ((pos + num) % k == 0) {
		ans++;
		cout << k << "down" << endl;
	  }
	}
	cout << "ans " << ans << endl;
  }
}