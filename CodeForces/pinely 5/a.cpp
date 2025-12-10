#include <iostream>
#include <utility>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int rating, x, d, n;
	cin >> rating >> x >> d >> n;
	string s;
	s.reserve(n);
	cin >> s;

	int out = 0;
	for (const char c : s) {
	  switch (c) {
	  case '1':
		out++;
		// adjust down rating
		if (rating >= x)
		  rating = max(x - 1, rating - d);
		break;
	  case '2':
		out += rating < x;
		// if participate then we are already under threshold, hence no rating change
		// if no participate then no rating change is possible
		break;
	  default:
		unreachable();
	  }
	}
	cout << out << "\n";
  }
  cout << flush;
}