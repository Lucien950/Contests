#include <iostream>
#include <sstream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n, m;
	string a, b, c;
	cin >> n >> a >> m >> b >> c;

	stringstream v_cont, d_cont;

	auto at = b.begin();
	for (const char& ch : c) {
	  switch (ch) {
	  case 'V':
		v_cont << *at;
		break;
	  case 'D':
		d_cont << *at;
		break;
	  default:
		throw exception();
	  }
	  ++at;
	}

	string v = v_cont.str(), d = d_cont.str();
	reverse(v.begin(), v.end());
	cout << v << a << d << "\n";
  }
  cout << flush;
}