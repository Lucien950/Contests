#include <iostream>
#include <numeric>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n;
	string s;
	cin >> s;
	string sorted_s = s;
	sort(sorted_s.begin(), sorted_s.end());
	if (s == sorted_s) {
	  cout << "Bob";
	} else {
	  cout << "Alice\n";
	  int out_n = 0;
	  for (int i = 0; i < n; i++) {
		out_n += s[i] != sorted_s[i];
	  }
	  cout << out_n << "\n";
	  for (int i = 0; i < n; i++) {
		if (s[i] != sorted_s[i]) {
		  cout << i + 1 << " ";
		}
	  }
	}

	cout << "\n";
  }
}