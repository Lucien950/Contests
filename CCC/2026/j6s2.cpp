#include <iostream>
#include <vector>
using namespace std;

int main() {
  int n, l, q;
  cin >> n >> l >> q;
  vector x(n, false);
  for (int i = 0; i < l; i++) {
	int pi, si;
	cin >> pi >> si;
	pi--;
	fill(x.begin() + max(pi - si, 0), x.begin() + min(pi + si, n - 1) + 1, true);
  }
  for (int i = 0; i < q; i++) {
	int qq;
	cin >> qq;
	cout << (x[qq - 1] ? 'Y' : 'N') << '\n';
  }
  cout << flush;
  return 0;
}