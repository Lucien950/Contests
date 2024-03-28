#include <cmath>
#include <iostream>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n; // n is odd!
	if (n == 1) {
	  cout << 1 << endl;
	  continue;
	}
	constexpr char permutations[2][3]{{'1', '9', '6'}, {'9', '6', '1'}};
	for (auto& p : permutations) {
	  for (int i = 1; i <= n / 2; i++) {
		auto out = string(n, '0');
		out[0] = p[0];
		out[i] = p[1];
		out[i * 2] = p[2];
		cout << out << " " << sqrt(stoi(out)) << endl;
	  }
	}
  }
}