#include <iostream>

using namespace std;

bool solve() {
  string s;
  cin >> s;
  int a = 0;
  bool seen = false;
  for (const char c : s) {
	switch (c) {
	case '(':
	  a++;
	  break;
	case ')':
	  a--;
	  break;
	default:
	  throw runtime_error("Invalid character in input string");
	}
	if (a == 0) {
	  if (!seen)
		seen = true;
	  else
		return true; // Found a second block
	}
  }
  return false;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
	cout << (solve() ? "YES" : "NO") << "\n";
  }
  cout << flush;
}