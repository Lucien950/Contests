#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n;
	std::string s;
	cin >> s;
	struct {
	  int a;
	  int b;
	  int c;
	  int d;
	} counts{};
	for (const char& c : s) {
	  switch (c) {
	  case 'A':
		counts.a++;
		break;
	  case 'B':
		counts.b++;
		break;
	  case 'C':
		counts.c++;
		break;
	  case 'D':
		counts.d++;
		break;
	  default:
		break;
	  }
	}

	cout << min(counts.a, n) + min(counts.b, n) + min(counts.c, n) + min(counts.d, n) << endl;
  }
}