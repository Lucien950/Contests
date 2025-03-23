#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n, k;
	cin >> n >> k;

	int out = 0;

	int pocket = 0;
	for (int i = 0; i < n; i++) {
	  int ai;
	  cin >> ai;
	  if (ai >= k) {
		pocket += ai;
	  } else {
		if (pocket > 0 && ai == 0) {
		  pocket--;
		  out += 1;
		}
	  }
	}
	cout << out << endl;
  }
}