#include <cstdint>
#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	uint32_t n;
	cin >> n;

	uint64_t ans = 0;
	bool neg_one_flip = false;
	for (uint32_t i = 0; i < n; i++) {
	  int32_t a;
	  cin >> a;
	  switch (a) {
	  case -1:
		neg_one_flip = !neg_one_flip;
		break;
	  case 0:
		ans++;
		break;
	  default:
		break;
	  }
	}

	ans += neg_one_flip * 2;

	cout << ans << "\n";
  }
  cout << flush;
}