#include <algorithm>
#include <iostream>
#include <ranges>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	size_t n;
	string s;
	cin >> n >> s;
	if (n == 1) {
	  cout << 1 << "\n";
	  continue;
	}
	int out = 0;
	int zero_streak = 1;
	for (size_t i = 0; i < n; i++) {
	  if (s[i] == '1') {
		// handle the zero_streak
		out += zero_streak / 3;
		// add the current 1
		out += 1;
		zero_streak = 0;
	  } else {
		// s[i] == 0
		zero_streak++;
	  }
	}
	// handle remaining zero_streak
	zero_streak++;
	out += zero_streak / 3;

	cout << out << "\n";
  }
  cout << flush;
}