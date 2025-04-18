#include <array>
#include <iostream>

using namespace std;

constexpr int MAX_N = 1e5;
static array<int, MAX_N> p{}, d{};

int main() {
  int t;
  cin >> t;

  while (t--) {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
	  cin >> p[i];
	}
	for (int i = 0; i < n; ++i) {
	  cin >> d[i];
	}

	int out = 0;
	for (int i = 0; i < n; i++) {
	  // add to out if there are more needed
	  for (int at = d[i] - 1; p[at] != 0;) {
		const int next = p[at] - 1;
		p[at] = 0;
		at = next;
		out++;
	  }
	  cout << out << " ";
	}
	cout << endl;
  }
}