#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	string s;
	cin >> s;
	ranges::reverse(s);
	for (const char& c : s) {
	  switch (c) {
	  case 'w':
		cout << "w";
		break;
	  case 'p':
		cout << "q";
		break;
	  case 'q':
		cout << "p";
		break;
	  default:;
	  }
	}
	cout << endl;
  }
}