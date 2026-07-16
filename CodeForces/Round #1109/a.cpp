#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int streak = 0;
	int max_s = 0;
	for (int i = 0; i < n; i++) {
	  switch (s[i]) {
	  case '*':
		max_s = max(max_s, streak);
		streak = 0;
		break;
	  case '#':
		streak += 1;
		break;
	  default:;
	  }
	}
	max_s = max(max_s, streak);
	cout << (max_s + 1) / 2 << endl;
  }
}