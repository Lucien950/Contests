#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int m, a, b, c;
	cin >> m >> a >> b >> c;
	cout << min(m, a) + min(m, b) + min(c, m - min(m, a) + (m - min(m, b))) << endl;
  }
}