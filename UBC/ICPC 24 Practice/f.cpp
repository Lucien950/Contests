#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;

  int expecting = 1;
  for (const char& c : s) {
	if (c - '0' == expecting) {
	  expecting++;
	} else {
	  cout << -1 << endl;
	  return EXIT_SUCCESS;
	}
  }

  cout << expecting - 1 << endl;
  return EXIT_SUCCESS;
}