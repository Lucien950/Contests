#include <cmath>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	int n;
	cin >> n;

	if (n == 5) {
	  cout << "5" << endl;
	  cout << "2 1 3 4 5" << endl;
	  continue;
	}

	std::vector<int> seq;
	const int target = n % 2 == 0 ? (1 << (static_cast<int>(::floor(::log2(n))) + 1)) - 1 : n;
	if ((target & 0b1) == 1) {
	  seq.push_back(5);
	}
	// start at the second digit
	for (int i = 1, d = target >> 1; d != 0; d >>= 1, i++) {
	  if ((d & 0b1) != 1)
		continue;
	  // and
	  seq.push_back((1 << i) - 1);
	  // or
	  seq.push_back(1 << i);
	}
	if (n % 2 == 1) {
	  seq.push_back(n);
	}

	cout << target << endl;
	const std::set used(seq.begin(), seq.end());
	for (int i = 1; i <= n; i++) {
	  if (!used.contains(i)) {
		cout << i << " ";
	  }
	}

	for (const int& i : seq) {
	  cout << i << " ";
	}
	cout << endl;
  }
}