#include <iostream>

using namespace std;

int main() {
  string s;
  cin >> s;

  int out = 1;
  int a = 0, b = 0, c = 0;
  for (const char& s0 : s) {
	switch (s0) {
	case 'A':
	  a++;
	  break;
	case 'B':
	  b++;
	  break;
	case 'C':
	  c++;
	  break;
	default:
	  return EXIT_FAILURE;
	}
	if (a > 0 && b > 0 && c > 0) {
	  a--;
	  b--;
	  c--;
	}
	out = max(out, max(a, max(b, c)));
  }
  cout << out << endl;
  return EXIT_SUCCESS;
}
