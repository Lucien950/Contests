#include <iostream>
using namespace std;

// inshallah
int factor_product(int n) {
  int out = 1;
  int z = 2;
  while (z * z <= n) {
	if (n % z == 0)
	  out *= z;
	while (n % z == 0) {
	  n /= z;
	}
	z++;
  }
  return n * out;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n;
	cout << factor_product(n) << '\n';
  }
  cout << flush;
}