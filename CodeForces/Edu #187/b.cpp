#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
	string x;
	cin >> x;
	array<int, 10> freq{};
	int fx = 0;
	for (size_t i = 0; i < x.size(); i++) {
	  const int v = x[i] - '0';
	  freq[v - (i == 0)] += 1;
	  fx += v;
	}

	int out = 0;
	while (fx >= 10) {
	  for (int i = 9; i >= 0; i--) {
		if (freq[i] > 0) {
		  fx -= i;
		  freq[i] -= 1;
		  out += 1;
		  break;
		}
	  }
	}
	cout << out << "\n";
  }
  cout << flush;
}